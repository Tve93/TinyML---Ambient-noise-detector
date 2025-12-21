import os
import numpy as np
import librosa
from collections import Counter

from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

import emlearn

# Configuration
SAMPLE_RATE = 16000
# Training on simple time-domain features (6 features):
# mean, rms, min, max, zero-crossing-rate, peak-to-peak
N_FEATURES = 6

DATA_DIR = os.path.join(os.path.dirname(__file__), "data")
SPEECH_DIR = os.path.join(DATA_DIR, "Speech")
NOISE_DIR = os.path.join(DATA_DIR, "Noise")

# Feature extraction
def extract_features(file_path):
    y, sr = librosa.load(file_path, sr=SAMPLE_RATE)

    # Convert to int16-like samples (match device raw samples)
    y_int = np.clip((y * 32768.0).astype(np.int32), -32768, 32767)

    # time-domain features computed over the whole file to match on-device extractor
    mean_v = float(np.mean(y_int))
    rms = float(np.sqrt(np.mean(y_int.astype(np.float64) * y_int.astype(np.float64))))
    min_v = float(np.min(y_int))
    max_v = float(np.max(y_int))

    # zero-crossing rate (frames -> average) computed on floats
    zcr_frames = librosa.feature.zero_crossing_rate(y, frame_length=512, hop_length=160)
    zcr = float(np.mean(zcr_frames))
    ptp = float(max_v - min_v)

    # Apply same scaling as device-side `features.h`
    mean_s = int(round(mean_v * 128.0))
    rms_s = int(round(rms * 64.0))
    min_s = int(round(min_v * 1.0))
    max_s = int(round(max_v * 1.0))
    zcr_s = int(round(zcr * 1000.0))
    ptp_s = int(round(ptp * 1.0))

    return np.array([mean_s, rms_s, min_s, max_s, zcr_s, ptp_s], dtype=np.int32)

# Build dataset
X = []
y = []

for file in os.listdir(SPEECH_DIR):
    if file.endswith(".wav"):
        X.append(extract_features(os.path.join(SPEECH_DIR, file)))
        y.append(1)  # speech

for file in os.listdir(NOISE_DIR):
    if file.endswith(".wav"):
        X.append(extract_features(os.path.join(NOISE_DIR, file)))
        y.append(0)  # noise

X = np.array(X, dtype=np.float32)
y = np.array(y, dtype=np.int32)

# Overall dataset counts
total_counts = Counter(y)
total_counts_simple = {int(k): v for k, v in total_counts.items()}
print(f"Total samples: {X.shape[0]} features: {X.shape[1] if X.size else 0}")
print("Total class distribution:", total_counts_simple)

# Train / test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Print train/test split sizes and class distributions
print(f"Train samples: {X_train.shape[0]} features: {X_train.shape[1]}")
train_counts = Counter(y_train)
train_counts_simple = {int(k): v for k, v in train_counts.items()}
print("Train class distribution:", train_counts_simple)
print(f"Test samples: {X_test.shape[0]} features: {X_test.shape[1]}")
test_counts = Counter(y_test)
test_counts_simple = {int(k): v for k, v in test_counts.items()}
print("Test class distribution:", test_counts_simple)


# Train Random Forest
rf = RandomForestClassifier(
    n_estimators=20,     # keep small for embedded
    max_depth=8,         # critical for flash size
    random_state=42
)

rf.fit(X_train, y_train)

# Evaluate
train_acc = accuracy_score(y_train, rf.predict(X_train))
test_acc = accuracy_score(y_test, rf.predict(X_test))

print(f"Train accuracy: {train_acc*100:.2f}%")
print(f"Test accuracy:  {test_acc*100:.2f}%")

# Convert to C with emlearn
c_model = emlearn.convert(
    rf,
    method="inline"
)

OUTPUT_HEADER = "speech_noise_model.h"
c_model.save(file=OUTPUT_HEADER)

print(f"\n✅ Model exported to {OUTPUT_HEADER}")
