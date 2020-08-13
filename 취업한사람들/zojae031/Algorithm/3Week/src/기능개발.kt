//import java.util.*
//
//fun main() {
//    Solution().solution(intArrayOf(93, 30, 55), intArrayOf(1, 30, 5))
//}
//
//class Solution {
//    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
//        var answer = mutableListOf<Int>()
//
//        val list: Queue<Int> = LinkedList<Int>()
//        //List 초기화
//        progresses.map {
//            //7 70 45 로 만들어주는 작업
//            SCORE - it
//        }.also {
//            // 7 2 9 로 만들어주는 작업
//            for (i in progresses.indices) {
//                list.add(it[i] / speeds[i])
//            }
//        }
//
//        while (list.isNotEmpty()) {
//            val head = list.remove()
//            var cnt = 1
//            while (list.isNotEmpty() && head >= list.peek()) {
//                cnt++
//                list.remove()
//            }
//            answer.add(cnt)
//        }
//        return answer.toIntArray()
//    }
//
//    companion object {
//        const val SCORE = 100
//    }
//}