//class Solution {
//    fun solution(n: Int): Int {
//        var answer = 0
//        for (i in 1..n) {
//            (n % i).takeIf { it == 0 }?.let { answer += i }
//        }
//        return answer
//    }
//}