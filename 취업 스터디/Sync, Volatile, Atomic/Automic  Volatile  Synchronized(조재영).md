# Automic / Volatile / Synchronized

1. Automic (원자성)
   
   - 원자성을 위한 함수
   
   - Compare And Swap(CAS) 방식을 선택
   
   - 1. 특정 메모리값 (reg)과 
   
     2. 넘겨받은값 oldval이 
   
        같을때에만 값을 변경한다
![image-20200108164909569](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20200108164909569.png)

   - 여러 스레드에서 읽기 쓰기 모두 가능



2. Volatile (가시성)

   - 가시성을 해결하기 위한 함수

   - 가시성이란? : 메인메모리에 접근하는지 cpu 메모리에 접근하는지 알 수 없음

     ![image-20200108165838204](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20200108165838204.png)

   - 하지만 경쟁상태의 문제 발생
   - 따라서 하나는 쓰기연산, 다른 하나는 읽기연산을 통해 **최신의 값**을 가져올 경우 사용가능

3. Synchronized (동기화)

   - 공유데이터, 함수 등에 lock을 걸어 가시성과 원자성을 확보한다.
     1. 함수에 lock : 함수에 거는것 같지만 객체에 lock을 걸어 객체에 포함된 다른 것들도 lock이 걸림
     2. 블록에 lock : 필요한 부분에만 동기화 처리하고 필요가 없는 부분은 그대로 둠



Q1. 각각의 키워드들을 언제 사용하면 좋을까?

1. Atomic : 해당 변수에 대한 원자성을 보장받을 때
2. synchronized : 연산의 범위를 지정할 때, 더 많은 작업을 처리할 때
3. Volatile : 다른 스레드에서는 읽기만 하고 한 스레드에서 쓰기만 할때, 멀티 CPU 프로세스일 때



Q2. Atomic과 Sync는 가시성을 보장받을까? [참고 포스팅](http://blog.naver.com/PostView.nhn?blogId=jjoommnn&logNo=130037479493)

보장받는다

``일반적으로 동기화를 위한 Lock 을 사용하는 곳에는 암시적으로 메모리 장벽이 설치된다. Lock이라는 것도 결국 Lock을 소유하는 코어(CPU)가 특정 메모리에 표시를 해 두면, 다른 코어(CPU)가 그 값을 보고 자신이 Lock을 소유할 수 없는 상태라는 것을 판단해야 하기 때문에, 이 Lock을 위한 메모리를 쓰고 읽는 과정에는 메모리 장벽이 필수적으로 들어가야 한다.``

``하지만 이 Atomic를 사용해야 하는 제일 중요한 이유는 메모리 가시성 때문이다. 이 Atomic에 값을 쓰거나 읽는 것은 레지스터나 캐쉬가 아니라 바로 메인 메모리에서 수행되도록 해 주는 것이다.``






