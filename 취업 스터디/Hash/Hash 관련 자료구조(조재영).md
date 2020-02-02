# Hash 관련 자료구조

### Hash란?

- 데이터를 다루는 기법 중 하나
- 다양한 길이의 데이터를 고정된 길이의 데이터로 매핑하는 것
- key-value 한쌍으로 존재하며 시간복잡도가 O(1)이다.

### Hash 함수란?

- 다양한 길이의 데이터를 고정된 길이의 데이터로 매핑하는 함수

  1. 제산법 : Moduler(%)를 이용하여 테이블 주소를 계산하는 방법

  2. 제곱법 : 키 값 제곱후 해시 테이블의 크기에 따라 주소 값 산출하는 방법

  3. 폴딩법 : xor을 사용하는 방법

### Hash 알고리즘 이란?

- Hash형태로 만들기 위한 다양한 알고리즘
- 해시 충돌 알고리즘
  1. Chaining : 캐시 충돌시 노드를 추가하여 다음 노드를 만드는 방법
     - 장점 : 유연함
     - 단점 : 메모리 문제를 야기 할 수 있음 (같은 공간에 충돌이 일어날 경우 비효율적)
  2. Open Addressing : 고정된 크기의 저장공간에 해시 함수를 사용하여 다음 공간으로 넣는 방법
     - 장점 : 메모리를 효율적으로 사용 할 수 있음
     - 단점 : 충돌이 자주 일어날 경우 효율성이 떨어짐



### Java의 hashcode

- 객체의 메모리 주소값을 이용해 해시코드를 만들어 리턴한다.



### HashMap

- key-value 로 맵핑되는 구조의 자료구조
- key값 비교를 hashcode를 사용하여 비교한다.
  - hashcode : 객체의 메모리주소를 이용하여 해시코드를 만드는 함수
- load factor을 이용하여 저장공간을 관리한다.
  - load factor : 한 공간에 저장된 데이터의 수
  - load factor == 저장된 데이터 수 / capacity
  - 메모리는 많이 먹어도 검색속도를 빠르게 하고싶다면 load factor를 작게 설정한다.

### HashTable

- HashMap과 완벽히 동일하지만 동기화를 지원한다 (synchronized)

### LinkedHashMap

- 입력 순서가 유지되는 HashMap

### TreeMap

- 정렬이 되는 Map 자료구조




> 입력 데이터 형태  ![image-20200131201134703](https://github.com/sejong-algorithm/Study/blob/master/%EC%B7%A8%EC%97%85%20%EC%8A%A4%ED%84%B0%EB%94%94/Hash/%EC%9E%85%EB%A0%A5%EB%8D%B0%EC%9D%B4%ED%84%B0.png?raw=true)
> 

>결과값  ![image-20200130154137267](https://github.com/sejong-algorithm/Study/blob/master/%EC%B7%A8%EC%97%85%20%EC%8A%A4%ED%84%B0%EB%94%94/Hash/%EC%B6%9C%EB%A0%A5%EB%8D%B0%EC%9D%B4%ED%84%B0.png?raw=true)
>

>코드  ![image-20200130154125301](https://github.com/sejong-algorithm/Study/blob/master/%EC%B7%A8%EC%97%85%20%EC%8A%A4%ED%84%B0%EB%94%94/Hash/%EC%BD%94%EB%93%9C.png?raw=true)
>





##### Question

- HashCode를 사용하여 비교하지 않는다면 어떤 문제가 발생할까?
  - value 비교를 통해 다른 객체가 들어와도 value가 같다면 같은 객체로 판단할것이다.
- HashMap을 사용하는 굉장히 메모리가 넉넉한 시스템에서 사용자 반응성을 더 빠르게 하고싶다. 어떻게 하면 좋을까?
  - load factor를 조정한다. 
  - 초기 capactiy를 예상된 데이터에 맞게 설정해준다.
- LinkedHashMap은 Thread Safe할까?
  - HashMap을 상속받고 있기 때문에 Safety하지 않다.
- HashMap, LinkedHashMap, TreeMap은 어떤 상황에서 사용하는것이 좋을까?
  1. HashMap : 일반적인 맵핑이 필요 할 때
  2. LinkedHashMap : 사진첩의 사진
  3. TreeMap : 범위검색이나 정렬이 필요 할 때