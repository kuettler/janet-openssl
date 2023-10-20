(use openssl)

(defn to-hex [msg]
  (string/join (seq [ch :in msg] (string/format "%02x" ch))))

(assert (= (to-hex (sha256 "Janet is awesome!")) "c07ad103111deb92b20a24a77652ede1a2c62b7ce368fdab9b640555c3de0e9d"))
(assert (= (to-hex (sha512 "Janet is awesome!")) "1e2beae95b2d7ad62fbf0326bbb2855719c9befc875be290369918356645f74a7a0c1279e008a9b6b0c7c79b705924a7b17ae97f47a343faa57d4fc8ace7f865"))
(assert (= (to-hex (hmac-sha512 "Janet is awesome!" "This is a secret.")) "a5e7e30fa751db9ae28cf01cb1a98f22b47e420c358257042013e15fbecdb45f40c1aeb5c66bd2a195fdc79ba4e5bef581df4fb05095c4f97f17fe2b51a7ca75"))
