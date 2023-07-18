# byte-order-transfer

## Big Endian & Little Endian

컴퓨터는 데이터를 메모리에 저장하기 위해 기본적으로 byte라는 단위를 사용한다.
이때 연속된 byte를 저장하는 방법을 Endian이라고 하는데, 현대 운영체제에는 크기 Big Endian과 Little Endian 방식으로 나뉜다.

### Big Endian

낮은 주소에 데이터를 **높은 비트(MSB, Most Significant Bit)** 부터 저장하는 방식이다.

```0x12345678``` 이라는 주소가 있다면, 낮은 주소에 데이터의 높은 비트 ```0x12``` 부터 시작해서 높은 주소로 채워지기 때문에 

- ```0x12```
- ```0x34```
- ```0x56```
- ```0x78```

과 같은 형태로 저장된다.

### Little Endian

낮은 주소에 데이터를 **낮은 비트(LSB, Least Significant Bit)** 부터 저장하는 방식이다.

```0x12345678``` 이라는 주소가 있다면, 낮은 주소에 데이터의 높은 비트 ```0x78``` 부터 시작해서 낮은 주소로 채워지기 때문에 

- ```0x78```
- ```0x56```
- ```0x34```
- ```0x12```

과 같은 형태로 저장한다.

## HBO & NBO

대부분 Intel CPU의 경우 Little Endian을 사용한다. 하지만 이처럼 시스템 관점에서의 Endian(HBO, Host Byte Order)만 있는 것이 아니라, 네트워크에서도 Byte Order를 다루기 위한 Endian이 존재(NBO, Network Byte Order)하는데, 이때 Big Endian을 사용한다.

그러므로 Intel 시스템에서 네트워크 통신을 할 때의 Byte Order인 Big Endian으로 변환해야 한다. 또한 네트워크로 데이터를 받는 호스트가 Little Endian을 기반으로 HBO가 되어 있다면, 역시 변환 과정을 거쳐야 한다.

C언어에서는 ```#include <netinet/in.h>``` 헤더를 이용하여 쉽게 변환할 수 있다.

해당 헤더를 이용하면 컴파일러가 해당 CPU가 Little Endian인지, Big Endian인지 알아서 판단하고, 내부적으로 적절하게 동작할 수 있게 처리하는 메서드를 제공한다.

|Conversion|C Function|Size|
|---|---|---|
|NBO to HBO|uint16_t ```ntohs```(uint16_t netshort)|2Byte|
|HBO to NBO|uint16_t ```htons```(uint16_t hostshort)|2Byte|
|NBO to HBO|uint32_t ```ntohl```(uint32_t netlong)|4Byte|
|HBO to NBO|uint32_t ```htonl```(uint32_t hostlong)|4Byte|




