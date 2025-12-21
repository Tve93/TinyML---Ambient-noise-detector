


    // !!! This file is generated using emlearn !!!

    #include <stdint.h>
    

static inline int32_t speech_noise_model_tree_0(const int16_t *features, int32_t features_length) {
          if (features[1] < 13029) {
              return 0;
          } else {
              if (features[4] < 224) {
                  if (features[4] < 124) {
                      return 1;
                  } else {
                      if (features[1] < 36351) {
                          if (features[1] < 33862) {
                              if (features[5] < 7382) {
                                  if (features[2] < -1696) {
                                      if (features[4] < 126) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[0] < -274) {
                                      if (features[0] < -571) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  } else {
                                      return 0;
                                  }
                              }
                          } else {
                              return 1;
                          }
                      } else {
                          if (features[4] < 205) {
                              if (features[0] < -720) {
                                  if (features[1] < 58892) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[2] < -7440) {
                                      if (features[4] < 134) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  } else {
                                      return 0;
                                  }
                              }
                          } else {
                              if (features[4] < 217) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          }
                      }
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_1(const int16_t *features, int32_t features_length) {
          if (features[2] < -2320) {
              if (features[4] < 229) {
                  if (features[4] < 82) {
                      if (features[0] < 663) {
                          return 0;
                      } else {
                          return 1;
                      }
                  } else {
                      if (features[5] < 19828) {
                          if (features[0] < -1984) {
                              if (features[0] < -2344) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              if (features[1] < 23267) {
                                  if (features[3] < 3430) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[4] < 175) {
                                      if (features[5] < 8738) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  } else {
                                      if (features[2] < -2520) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              }
                          }
                      } else {
                          return 0;
                      }
                  }
              } else {
                  if (features[0] < -1112) {
                      if (features[0] < -1996) {
                          return 0;
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[1] < 12275) {
                  return 0;
              } else {
                  if (features[4] < 114) {
                      return 1;
                  } else {
                      if (features[3] < 1258) {
                          if (features[3] < 1226) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          if (features[4] < 203) {
                              if (features[2] < -1924) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_2(const int16_t *features, int32_t features_length) {
          if (features[4] < 176) {
              if (features[5] < 2704) {
                  return 0;
              } else {
                  if (features[3] < 5390) {
                      if (features[2] < -2588) {
                          if (features[1] < 15846) {
                              return 0;
                          } else {
                              if (features[3] < 4782) {
                                  if (features[4] < 158) {
                                      return 1;
                                  } else {
                                      if (features[0] < 52) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              } else {
                                  if (features[3] < 5196) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          }
                      } else {
                          if (features[0] < -772) {
                              return 0;
                          } else {
                              if (features[5] < 4934) {
                                  if (features[0] < 181) {
                                      return 1;
                                  } else {
                                      if (features[5] < 4104) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      }
                  } else {
                      if (features[3] < 6398) {
                          return 0;
                      } else {
                          if (features[5] < 22162) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  }
              }
          } else {
              if (features[2] < -1696) {
                  if (features[2] < -3316) {
                      if (features[0] < -270) {
                          if (features[3] < 5840) {
                              if (features[2] < -4026) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[4] < 184) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      if (features[5] < 5202) {
                          if (features[5] < 5092) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[1] < 31880) {
                              return 1;
                          } else {
                              if (features[5] < 5822) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          }
                      }
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_3(const int16_t *features, int32_t features_length) {
          if (features[2] < -2320) {
              if (features[3] < 5334) {
                  if (features[4] < 253) {
                      if (features[4] < 82) {
                          if (features[1] < 18604) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          if (features[3] < 4738) {
                              if (features[4] < 146) {
                                  return 1;
                              } else {
                                  if (features[1] < 15654) {
                                      return 0;
                                  } else {
                                      if (features[3] < 2592) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          } else {
                              if (features[3] < 5196) {
                                  if (features[3] < 4966) {
                                      return 0;
                                  } else {
                                      if (features[2] < -4330) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              } else {
                                  return 1;
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              } else {
                  if (features[3] < 8470) {
                      if (features[4] < 174) {
                          return 1;
                      } else {
                          return 0;
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[1] < 12275) {
                  return 0;
              } else {
                  if (features[1] < 18156) {
                      return 1;
                  } else {
                      if (features[3] < 1282) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_4(const int16_t *features, int32_t features_length) {
          if (features[5] < 11846) {
              if (features[2] < -2320) {
                  if (features[0] < 451) {
                      if (features[1] < 19581) {
                          if (features[3] < 2826) {
                              if (features[0] < -285) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[1] < 79222) {
                              if (features[3] < 4672) {
                                  if (features[3] < 2312) {
                                      return 1;
                                  } else {
                                      if (features[5] < 5518) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  if (features[3] < 5196) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      return 1;
                  }
              } else {
                  if (features[4] < 113) {
                      return 1;
                  } else {
                      if (features[1] < 14334) {
                          return 0;
                      } else {
                          if (features[4] < 164) {
                              return 0;
                          } else {
                              if (features[0] < 45) {
                                  if (features[5] < 2716) {
                                      return 0;
                                  } else {
                                      if (features[4] < 212) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      }
                  }
              }
          } else {
              return 0;
          }
        }
        

static inline int32_t speech_noise_model_tree_5(const int16_t *features, int32_t features_length) {
          if (features[1] < 13029) {
              return 0;
          } else {
              if (features[5] < 19828) {
                  if (features[2] < -2320) {
                      if (features[4] < 253) {
                          if (features[3] < 4650) {
                              if (features[1] < 16997) {
                                  return 0;
                              } else {
                                  if (features[4] < 146) {
                                      return 1;
                                  } else {
                                      if (features[5] < 5224) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          } else {
                              if (features[3] < 7038) {
                                  return 0;
                              } else {
                                  if (features[5] < 16518) {
                                      if (features[5] < 15284) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  } else {
                                      return 1;
                                  }
                              }
                          }
                      } else {
                          return 0;
                      }
                  } else {
                      if (features[1] < 19866) {
                          if (features[4] < 240) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          return 0;
                      }
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_6(const int16_t *features, int32_t features_length) {
          if (features[4] < 169) {
              if (features[4] < 128) {
                  if (features[1] < 14265) {
                      return 0;
                  } else {
                      return 1;
                  }
              } else {
                  if (features[5] < 4152) {
                      return 0;
                  } else {
                      if (features[3] < 4738) {
                          if (features[0] < 65) {
                              return 1;
                          } else {
                              if (features[0] < 179) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          }
                      } else {
                          if (features[1] < 88179) {
                              return 0;
                          } else {
                              return 1;
                          }
                      }
                  }
              }
          } else {
              if (features[5] < 9580) {
                  if (features[5] < 5524) {
                      if (features[2] < -1704) {
                          if (features[4] < 176) {
                              if (features[1] < 13007) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          } else {
                              if (features[3] < 2418) {
                                  return 0;
                              } else {
                                  if (features[4] < 202) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          }
                      } else {
                          return 0;
                      }
                  } else {
                      if (features[4] < 242) {
                          if (features[4] < 204) {
                              return 1;
                          } else {
                              if (features[1] < 38052) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          }
                      } else {
                          return 0;
                      }
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_7(const int16_t *features, int32_t features_length) {
          if (features[5] < 4636) {
              if (features[4] < 116) {
                  if (features[1] < 9970) {
                      return 0;
                  } else {
                      return 1;
                  }
              } else {
                  if (features[2] < -1696) {
                      if (features[2] < -1756) {
                          if (features[0] < -711) {
                              if (features[3] < 2018) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[5] < 3134) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[3] < 4838) {
                  if (features[4] < 252) {
                      if (features[5] < 5524) {
                          if (features[1] < 32466) {
                              if (features[1] < 17735) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[4] < 82) {
                              if (features[4] < 73) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              if (features[1] < 23635) {
                                  if (features[1] < 23112) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  return 1;
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              } else {
                  if (features[1] < 85843) {
                      if (features[1] < 52013) {
                          return 0;
                      } else {
                          if (features[1] < 81945) {
                              if (features[3] < 12258) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      if (features[4] < 215) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_8(const int16_t *features, int32_t features_length) {
          if (features[4] < 182) {
              if (features[3] < 1666) {
                  if (features[4] < 114) {
                      if (features[5] < 1664) {
                          return 0;
                      } else {
                          return 1;
                      }
                  } else {
                      if (features[2] < -1724) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              } else {
                  if (features[4] < 136) {
                      if (features[1] < 15064) {
                          return 0;
                      } else {
                          if (features[1] < 42166) {
                              return 1;
                          } else {
                              if (features[1] < 42753) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          }
                      }
                  } else {
                      if (features[4] < 151) {
                          if (features[1] < 46058) {
                              if (features[2] < -2666) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[2] < -5090) {
                              if (features[4] < 175) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          } else {
                              if (features[1] < 33626) {
                                  return 1;
                              } else {
                                  if (features[2] < -3112) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              }
                          }
                      }
                  }
              }
          } else {
              if (features[1] < 26199) {
                  return 0;
              } else {
                  if (features[3] < 3416) {
                      if (features[2] < -2798) {
                          return 1;
                      } else {
                          return 0;
                      }
                  } else {
                      if (features[3] < 4818) {
                          if (features[5] < 8196) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          return 0;
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_9(const int16_t *features, int32_t features_length) {
          if (features[4] < 184) {
              if (features[3] < 1086) {
                  return 0;
              } else {
                  if (features[1] < 81945) {
                      if (features[5] < 12168) {
                          if (features[5] < 3810) {
                              if (features[5] < 3134) {
                                  if (features[4] < 124) {
                                      return 1;
                                  } else {
                                      if (features[5] < 2820) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  return 0;
                              }
                          } else {
                              if (features[4] < 82) {
                                  if (features[3] < 3170) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[5] < 5452) {
                                      if (features[3] < 2366) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  } else {
                                      if (features[1] < 45453) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          }
                      } else {
                          if (features[2] < -8414) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      if (features[2] < -6602) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              }
          } else {
              if (features[0] < 507) {
                  if (features[3] < 4818) {
                      if (features[3] < 4352) {
                          if (features[4] < 202) {
                              if (features[5] < 1560) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          } else {
                              if (features[0] < -974) {
                                  if (features[0] < -1251) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              } else {
                  if (features[3] < 15696) {
                      return 1;
                  } else {
                      return 0;
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_10(const int16_t *features, int32_t features_length) {
          if (features[4] < 175) {
              if (features[4] < 128) {
                  if (features[2] < -2070) {
                      if (features[3] < 3744) {
                          return 1;
                      } else {
                          if (features[5] < 8522) {
                              return 0;
                          } else {
                              return 1;
                          }
                      }
                  } else {
                      if (features[0] < -384) {
                          return 0;
                      } else {
                          return 1;
                      }
                  }
              } else {
                  if (features[1] < 17409) {
                      return 0;
                  } else {
                      if (features[5] < 2820) {
                          return 0;
                      } else {
                          if (features[3] < 4782) {
                              if (features[0] < 65) {
                                  return 1;
                              } else {
                                  if (features[2] < -4722) {
                                      return 0;
                                  } else {
                                      if (features[0] < 179) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          } else {
                              if (features[3] < 7182) {
                                  return 0;
                              } else {
                                  if (features[4] < 134) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              }
                          }
                      }
                  }
              }
          } else {
              if (features[4] < 221) {
                  if (features[1] < 14365) {
                      return 0;
                  } else {
                      if (features[3] < 8634) {
                          if (features[2] < -4470) {
                              return 1;
                          } else {
                              if (features[2] < -3980) {
                                  return 0;
                              } else {
                                  if (features[1] < 32466) {
                                      if (features[3] < 1592) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  } else {
                                      if (features[5] < 5530) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          }
                      } else {
                          return 0;
                      }
                  }
              } else {
                  if (features[3] < 2450) {
                      if (features[3] < 2380) {
                          return 0;
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_11(const int16_t *features, int32_t features_length) {
          if (features[1] < 13172) {
              return 0;
          } else {
              if (features[4] < 249) {
                  if (features[5] < 23310) {
                      if (features[4] < 129) {
                          if (features[5] < 7694) {
                              return 1;
                          } else {
                              if (features[2] < -4014) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          }
                      } else {
                          if (features[2] < -2678) {
                              if (features[5] < 7682) {
                                  if (features[1] < 39839) {
                                      return 1;
                                  } else {
                                      if (features[5] < 6648) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  if (features[3] < 4782) {
                                      if (features[3] < 3754) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  } else {
                                      if (features[3] < 7566) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          } else {
                              if (features[0] < 205) {
                                  if (features[3] < 2294) {
                                      if (features[2] < -1696) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_12(const int16_t *features, int32_t features_length) {
          if (features[2] < -2364) {
              if (features[2] < -6980) {
                  if (features[3] < 8470) {
                      if (features[5] < 16518) {
                          if (features[1] < 63168) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              } else {
                  if (features[3] < 4882) {
                      if (features[1] < 20547) {
                          if (features[3] < 2484) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[4] < 253) {
                              if (features[4] < 157) {
                                  return 1;
                              } else {
                                  if (features[4] < 179) {
                                      return 0;
                                  } else {
                                      if (features[2] < -2844) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              }
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      if (features[0] < 88) {
                          if (features[4] < 127) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[2] < -5108) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  }
              }
          } else {
              if (features[4] < 122) {
                  if (features[4] < 94) {
                      return 0;
                  } else {
                      return 1;
                  }
              } else {
                  if (features[4] < 203) {
                      if (features[3] < 1230) {
                          return 0;
                      } else {
                          if (features[1] < 19034) {
                              if (features[5] < 3734) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      return 0;
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_13(const int16_t *features, int32_t features_length) {
          if (features[1] < 13919) {
              return 0;
          } else {
              if (features[4] < 182) {
                  if (features[3] < 4738) {
                      if (features[2] < -2588) {
                          return 1;
                      } else {
                          if (features[3] < 2322) {
                              if (features[2] < -2046) {
                                  return 1;
                              } else {
                                  if (features[4] < 128) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              }
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      if (features[3] < 5196) {
                          return 0;
                      } else {
                          if (features[2] < -6190) {
                              return 1;
                          } else {
                              if (features[3] < 5370) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          }
                      }
                  }
              } else {
                  if (features[3] < 3296) {
                      if (features[1] < 29245) {
                          if (features[5] < 5996) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          if (features[1] < 37399) {
                              if (features[4] < 280) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          } else {
                              if (features[2] < -4210) {
                                  return 1;
                              } else {
                                  return 0;
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_14(const int16_t *features, int32_t features_length) {
          if (features[2] < -2314) {
              if (features[3] < 5390) {
                  if (features[3] < 3458) {
                      if (features[2] < -5196) {
                          return 0;
                      } else {
                          if (features[0] < -1707) {
                              return 0;
                          } else {
                              if (features[2] < -2670) {
                                  return 1;
                              } else {
                                  if (features[5] < 4872) {
                                      return 1;
                                  } else {
                                      if (features[4] < 207) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          }
                      }
                  } else {
                      if (features[2] < -4038) {
                          if (features[1] < 33231) {
                              return 0;
                          } else {
                              if (features[2] < -4696) {
                                  return 1;
                              } else {
                                  if (features[0] < -462) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          }
                      } else {
                          if (features[0] < -858) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  }
              } else {
                  if (features[5] < 19828) {
                      if (features[2] < -8676) {
                          if (features[3] < 9094) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[4] < 117) {
                              return 1;
                          } else {
                              return 0;
                          }
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[4] < 113) {
                  return 1;
              } else {
                  if (features[5] < 2922) {
                      return 0;
                  } else {
                      if (features[0] < -265) {
                          if (features[1] < 15760) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          return 0;
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_15(const int16_t *features, int32_t features_length) {
          if (features[4] < 221) {
              if (features[1] < 13919) {
                  return 0;
              } else {
                  if (features[5] < 19828) {
                      if (features[5] < 4014) {
                          if (features[3] < 1492) {
                              if (features[0] < -176) {
                                  if (features[3] < 1350) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              } else {
                                  return 1;
                              }
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[5] < 10354) {
                              if (features[3] < 4782) {
                                  if (features[4] < 136) {
                                      return 1;
                                  } else {
                                      if (features[1] < 17636) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  if (features[3] < 4966) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          } else {
                              if (features[4] < 124) {
                                  return 1;
                              } else {
                                  if (features[1] < 88179) {
                                      return 0;
                                  } else {
                                      return 1;
                                  }
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[0] < -929) {
                  if (features[0] < -1251) {
                      return 0;
                  } else {
                      return 1;
                  }
              } else {
                  if (features[4] < 229) {
                      if (features[2] < -2580) {
                          return 1;
                      } else {
                          return 0;
                      }
                  } else {
                      return 0;
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_16(const int16_t *features, int32_t features_length) {
          if (features[3] < 5394) {
              if (features[4] < 221) {
                  if (features[5] < 4014) {
                      if (features[1] < 19814) {
                          if (features[3] < 760) {
                              return 0;
                          } else {
                              return 1;
                          }
                      } else {
                          return 0;
                      }
                  } else {
                      if (features[1] < 17636) {
                          return 0;
                      } else {
                          if (features[0] < -656) {
                              return 1;
                          } else {
                              if (features[1] < 79222) {
                                  if (features[3] < 4902) {
                                      if (features[4] < 204) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  } else {
                                      if (features[3] < 5196) {
                                          return 0;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      }
                  }
              } else {
                  if (features[0] < 230) {
                      return 0;
                  } else {
                      if (features[4] < 245) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              }
          } else {
              if (features[4] < 128) {
                  return 1;
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_17(const int16_t *features, int32_t features_length) {
          if (features[3] < 4922) {
              if (features[4] < 140) {
                  if (features[3] < 746) {
                      return 0;
                  } else {
                      if (features[5] < 3632) {
                          if (features[3] < 1492) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          if (features[0] < 212) {
                              if (features[5] < 7512) {
                                  if (features[4] < 136) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[0] < -625) {
                                      return 1;
                                  } else {
                                      if (features[0] < -132) {
                                          return 0;
                                      } else {
                                          return 0;
                                      }
                                  }
                              }
                          } else {
                              return 1;
                          }
                      }
                  }
              } else {
                  if (features[2] < -1924) {
                      if (features[0] < 453) {
                          if (features[0] < -264) {
                              if (features[0] < -1102) {
                                  return 0;
                              } else {
                                  if (features[1] < 20818) {
                                      return 0;
                                  } else {
                                      if (features[2] < -4572) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          } else {
                              if (features[5] < 5356) {
                                  if (features[4] < 231) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  if (features[1] < 33002) {
                                      return 0;
                                  } else {
                                      if (features[1] < 37887) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              }
                          }
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[1] < 75164) {
                  return 0;
              } else {
                  if (features[2] < -6980) {
                      return 0;
                  } else {
                      if (features[4] < 272) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_18(const int16_t *features, int32_t features_length) {
          if (features[4] < 187) {
              if (features[2] < -1222) {
                  if (features[3] < 5390) {
                      if (features[4] < 82) {
                          if (features[4] < 70) {
                              return 1;
                          } else {
                              if (features[1] < 27000) {
                                  return 0;
                              } else {
                                  return 1;
                              }
                          }
                      } else {
                          if (features[1] < 13688) {
                              return 0;
                          } else {
                              if (features[0] < -1109) {
                                  if (features[1] < 25665) {
                                      return 0;
                                  } else {
                                      if (features[2] < -4272) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  }
                              } else {
                                  if (features[3] < 2592) {
                                      return 1;
                                  } else {
                                      if (features[4] < 128) {
                                          return 1;
                                      } else {
                                          return 1;
                                      }
                                  }
                              }
                          }
                      }
                  } else {
                      if (features[0] < -1448) {
                          return 1;
                      } else {
                          return 0;
                      }
                  }
              } else {
                  return 0;
              }
          } else {
              if (features[4] < 221) {
                  if (features[1] < 26608) {
                      return 0;
                  } else {
                      if (features[0] < -475) {
                          return 0;
                      } else {
                          if (features[4] < 194) {
                              return 0;
                          } else {
                              if (features[2] < -3316) {
                                  if (features[2] < -3866) {
                                      return 1;
                                  } else {
                                      return 0;
                                  }
                              } else {
                                  return 1;
                              }
                          }
                      }
                  }
              } else {
                  return 0;
              }
          }
        }
        

static inline int32_t speech_noise_model_tree_19(const int16_t *features, int32_t features_length) {
          if (features[2] < -2320) {
              if (features[3] < 5302) {
                  if (features[4] < 254) {
                      if (features[1] < 15064) {
                          return 0;
                      } else {
                          if (features[4] < 140) {
                              return 1;
                          } else {
                              if (features[3] < 4838) {
                                  if (features[0] < -217) {
                                      return 1;
                                  } else {
                                      if (features[3] < 2460) {
                                          return 1;
                                      } else {
                                          return 0;
                                      }
                                  }
                              } else {
                                  return 0;
                              }
                          }
                      }
                  } else {
                      return 0;
                  }
              } else {
                  if (features[3] < 8448) {
                      if (features[5] < 16518) {
                          if (features[4] < 111) {
                              return 1;
                          } else {
                              return 0;
                          }
                      } else {
                          return 1;
                      }
                  } else {
                      return 0;
                  }
              }
          } else {
              if (features[1] < 12791) {
                  return 0;
              } else {
                  if (features[4] < 122) {
                      return 1;
                  } else {
                      return 0;
                  }
              }
          }
        }
        

int32_t speech_noise_model_predict(const int16_t *features, int32_t features_length) {

        int32_t votes[2] = {0,};
        int32_t _class = -1;

        _class = speech_noise_model_tree_0(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_1(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_2(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_3(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_4(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_5(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_6(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_7(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_8(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_9(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_10(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_11(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_12(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_13(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_14(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_15(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_16(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_17(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_18(features, features_length); votes[_class] += 1;
    _class = speech_noise_model_tree_19(features, features_length); votes[_class] += 1;
    
        int32_t most_voted_class = -1;
        int32_t most_voted_votes = 0;
        for (int32_t i=0; i<2; i++) {

            if (votes[i] > most_voted_votes) {
                most_voted_class = i;
                most_voted_votes = votes[i];
            }
        }
        return most_voted_class;
    }
    

int speech_noise_model_predict_proba(const int16_t *features, int32_t features_length, float *out, int out_length) {

        int32_t _class = -1;

        for (int i=0; i<out_length; i++) {
            out[i] = 0.0f;
        }

        _class = speech_noise_model_tree_0(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_1(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_2(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_3(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_4(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_5(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_6(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_7(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_8(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_9(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_10(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_11(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_12(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_13(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_14(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_15(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_16(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_17(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_18(features, features_length); out[_class] += 1.0f;
    _class = speech_noise_model_tree_19(features, features_length); out[_class] += 1.0f;
    
        // compute mean
        for (int i=0; i<out_length; i++) {
            out[i] = out[i] / 20;
        }
        return 0;
    }
    