# Sync, Volatile, Atomic (2020-01-13)

- Volatile : 가시성을 준수, 메인메모리에 값을 강제한다.

- Sync :  Lock을 걸어 동시접근을 제한한다.

- Atomic : Compare and Swap



가시성 문제를 해결한다는게 무슨말인가?

 -> 캐시에서 가져오는지 메모리에서 가져오는지 모르니까.

 -> 캐시에 저장된 값이랑 메인메모리에 있는 값이랑 다르니까.