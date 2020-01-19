package `3week`

//fun main() {
//    Solution().run {
//        solution(intArrayOf(2, 1, 3, 2), 2)
//            .also { println(it) }//1
//
//        solution(intArrayOf(1, 1, 9, 1, 1, 1), 0)
//            .also { println(it) }//5
//    }
//}
//
//class Solution {
//    fun solution(priorities: IntArray, location: Int): Int {
//        var answer = 1
//        /** Queue 형태로 만들어주는 작업
//         * first : 2 1 3 2
//         * second : 0 1 2 3
//         */
//        val queue: MutableList<Pair<Int, Int>> = priorities.mapIndexed { index, i ->
//            i to index
//        }.toMutableList()
//
//        while (queue.isNotEmpty()) {
//            /**
//             * max : 최대값을 구함
//             * value : 큐의 맨 앞부분
//             */
//            val max = queue.maxBy { it.first }!!
//            val value = queue.first()
//
//            when {// 순서가 굉장히 중요함
//                value.first < max.first -> { //최대값보다 작으면 뒤로 돌림
//                    queue.remove(value)
//                    queue.add(value)
//                }
//                value.first == max.first && value.second != location -> { //제일 큰값이면서 원하는 값이 아니면
//                    queue.remove(value)//제거 후
//                    answer++//카운트 증가
//                }
//                value.second == location -> {//원하는 값이 나온다면 출력
//                    return answer
//                }
//            }
//
//        }
//        return answer
//    }
//}