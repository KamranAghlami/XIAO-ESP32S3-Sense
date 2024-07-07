# XIAO-ESP32S3-Sense
A boilerplate project for Seeed Studio's [XIAO-ESP32S3-Sense](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html) using the [PlatformIO](https://platformio.org) IDE and the [Arduino](https://www.arduino.cc/) framework.

**Features**:
 - Takes care of initializing the hardware.
 - Initializes the external PSRAM.
 - Mounts the internal flash as a storage medium.
 
 **Partition Table**:

The 8MB flash is partitioned as follows, there are 20KBs of space allocated as `nvs` key-value storage, an `otadata` partition, and two `app` partitions defined, 2MBs each, so OTA updates can be supported as well. And finally 3.93MBs of space is allocated to the `storage` partition that is available to the user to work with.

| Name     | Type | SubType | Offset   | Size     |
|----------|------|---------|----------|----------|
| nvs      | data | nvs     | 0x9000   | 0x5000   |
| otadata  | data | ota     | 0xe000   | 0x2000   |
| app0     | app  | ota_0   | 0x10000  | 0x200000 |
| app1     | app  | ota_1   | 0x210000 | 0x200000 |
| storage  | data | spiffs  | 0x410000 | 0x3f0000 |

## Getting Started
It is as easy as inheriting from the `application` class and overriding `on_create` and `on_update` methods. 

Check out the [example.cpp](src/example/example.cpp) file, It's provided to help as a starting point.

**Note:** As mentioned, this example utilizes Espressif's [Storage API](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/api-reference/storage/index.html), so if you're building from source don't forget to build and upload the filesystem image as well before the first use.

## Try it out

Got your board at hand? Download the latest [release](https://github.com/KamranAghlami/T-Display-S3/releases/latest) and flash online via [ESP Tool](https://espressif.github.io/esptool-js). Use the provided `offsets.json` file to specify which address to flash each bin file to.
