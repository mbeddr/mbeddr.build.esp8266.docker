FROM ubuntu
MAINTAINER marcelstoer

# If you want to tinker with this Dockerfile on your machine do as follows:
# - git clone https://github.com/marcelstoer/docker-nodemcu-build
# - vim docker-nodemcu-build/Dockerfile
# - docker build -t docker-nodemcu-build docker-nodemcu-build
# - cd <nodemcu-firmware
# - docker run --rm -ti -v `pwd`:/opt/nodemcu-firmware docker-nodemcu-build

RUN apt-get update -y && apt-get install -y wget unzip git make python-serial srecord bc
RUN mkdir /opt/nodemcu-firmware
WORKDIR /opt/nodemcu-firmware

# Config options you may pass via Docker like so 'docker run -e "<option>=<value>"':
# - IMAGE_NAME=<name>, define a static name for your .bin files
# - INTEGER_ONLY=1, if you want the integer firmware
# - FLOAT_ONLY=1, if you want the floating point firmware
#
# What the commands do:
# - use the Git branch and the current time stamp to define image name if IMAGE_NAME not set
# - unpack esp-open-sdk.tar.gz in a directory that is NOT the bound mount directory (i.e. inside the Docker image)
# - remove all files in <firmware-dir>/bin
# - make a float build if !only-integer
# - copy and rename the mapfile to bin/
# - make an integer build
# - copy and rename the mapfile to bin/
ADD ./tools /opt/tools
RUN cd /opt/tools && cp esp-open-sdk.tar.gz ../ && cd .. && tar -zxvf esp-open-sdk.tar.gz
ADD ./sdk /opt/sdk
ADD ./sdk-overrides /opt/sdk-overrides
ENV PATH $PATH:/opt/esp-open-sdk/sdk:/opt/esp-open-sdk/xtensa-lx106-elf/bin
CMD export PATH=$PATH:/opt/esp-open-sdk/sdk:/opt/esp-open-sdk/xtensa-lx106-elf/bin && make clean all SDK_BASE=/opt/sdk/esp_iot_sdk_v1.5.3 ESPTOOL=/opt/tools/esptool.py XTENSA_TOOLS_ROOT=/opt/esp-open-sdk/xtensa-lx106-elf/bin