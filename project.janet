(declare-project
  :name "openssl"
  :description ```Hash functions from openssl.```
  )

(def cflags '[])
(def lflags '["-lcrypto"])

(declare-native
  :name "openssl"
  :source @["module.c"]
  :cflags [;default-cflags ;cflags]
  :lflags [;default-lflags ;lflags]
  )
