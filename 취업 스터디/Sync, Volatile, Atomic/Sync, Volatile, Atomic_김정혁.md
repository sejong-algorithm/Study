### atomic , volatilie , synchronized 비교
#####  - java에서 멀티프로그래밍을 할때 발생하는 문제점  
- **경쟁 상태**
  - 여러 스레드가 같은 시점 변수를 동시에 읽을때
- **변수의 가시성**
  - 사용될 변수들이 어디서 오는지 알 수 없는 문제(CPU memory or Main memory)
  - 멀티코어 환경에서 각 cpu는 메인 메모리에서 변수값을 참조하는게 아니라 각 cpu의 캐시 영역에 메모리 값을 참조하는데 이때 메인메모리에 저장된 값과 cpu 캐시영역에 저장된 갑싱 다른경우!
##### - 이를 해결하기 위한 방법 (atomic, volatile, synchronized 사용)

- **Atomic** 
  - 실제로 AtomicInteger 를 사용하여 변수를 선언
  - AtomicInteger 클래스는  CAS(Compare-and-swap) 기반으로 특정 메모리 위치의 값이 주어진 값을 비교하여 같으면 새로운 값으로 대체한다.
  - 원자적 연산 지원
  - 여러 스레드에서 읽기 쓰기 모두 이용 가능
- **Volatile**
  - volatile 키워드 사용하여 변수를 선언
  - 변수를 읽고 쓰는 과정을 모두 메인 메모리에서만 처리된다. 
  - 변수의 가시성은 해결되지만 경쟁 상태에 대한 문제점은 해결하기 힘들다
 - **Synchronized** 
   - 하나의 쓰레드가 lock을 얻어 동작이 끝날때까지 다른 스레드들은 lock이 풀릴 때까지 대기한다.
   - 여러 스레드에서 읽기 쓰기 모두 이용 가능

 <질문>

-멀티쓰레드 프로그래밍을 진행할 때 문제
-atomic 과 volatile과 synchronized의 차이점



