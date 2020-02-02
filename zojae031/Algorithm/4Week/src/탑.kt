//package `4week`
//
//class Solution {
//    fun solution(heights: IntArray): IntArray {
//        var answer = mutableListOf<Int>()
//        for (i in heights.size - 1 downTo 0) {
//            for (j in i - 1 downTo 0) {
//                if (heights[i] < heights[j]) {
//                    answer.add(j + 1)
//                    break
//                }
//                if (j == 0) answer.add(0)
//            }
//        }
//        answer.add(0)
//
//        return answer.reversed().toIntArray()
//    }
//}