//import java.util.*
//
//fun main() {
//    Solution().run {
//        solution("()(((()())(())()))(())")
//            .also { println(it) }
//    }
//}
//
//class Solution {
//    fun solution(arrangement: String): Int {
//        var answer = 0
//        val lasers = mutableListOf<Int>()
//        val stack = Stack<Pair<Char, Int>>()
//
//        for (i in arrangement.indices) {
//
//            if (stack.isNotEmpty()) {
//
//                if (stack.peek().first == '(' && arrangement[i] == ')') {
//
//                    if (stack.peek().second == i - 1) {//레이저 검출
//                        lasers.add(i)
//                    } else {//쇠 파이프 검출
//                        var cnt = 0
//
//                        for (laser in lasers) {
//                            //쇠막대기 시작 인덱스 {stack.peek().second}
//                            //쇠막대기 끝 인덱스 { i } 안에 laser 가 존재하는지 확인
//                            if (laser > stack.peek().second && laser < i) {
//                                cnt++
//                            }
//                        }
//
//                        if (cnt != 0) {//잘렸다면 잘린 개수 +1 개 만큼 더 생기니까 +1
//                            answer += cnt + 1
//                        }
//
//                    }
//                    stack.pop()
//                    continue
//                }
//            }
//
//            stack.push(arrangement[i] to i)
//
//        }
//        return answer
//    }
//}

fun call(c: Int): Int{
    return c
}

fun main(){
    val b :() ->Int = {
        1}
    print(b)
   print( call(b()))

}