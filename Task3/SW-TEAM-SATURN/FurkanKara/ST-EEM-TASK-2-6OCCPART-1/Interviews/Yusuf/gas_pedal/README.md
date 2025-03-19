# Gaz Pedalı Kontrol Modülü

## Açıklama

Linux ortamında C dilinde geliştirilmiş bu proje, gaz pedalından analog verileri okuyup motor hızını hesaplamayı amaçlamaktadır.

## Dosya Yapısı

proje/
├── include/       (header dosyaları)
├── src/           (app_main.c, controller.c, interface.c, system.c, logger.c)
├── Makefile
└── README.md

## Derleme ve Çalıştırma

Derlemek için:

```console
make
```

Çalıştırmak için:

```console
./gas_pedal
```

Temizlemek için:

```console
make clean
```


## Notlar

- Analog veri, sinüs fonksiyonu ile simüle edilmektedir.
- Derleme sırasında `-lm` bayrağı matematik kütüphanesi için kullanılır.
