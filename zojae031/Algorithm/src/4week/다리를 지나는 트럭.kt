//package `4week`
//
//import java.util.*
//
//class Solution {
//    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
//        var answer = 0
//        val readyQueue: Queue<Int> = LinkedList()
//        val goingQueue: Queue<Pair<Int, Int>> = LinkedList()
//
//        var nowWeight = 0
//
//        truck_weights.forEach {
//            readyQueue.add(it)
//        }
//
//        while (readyQueue.isNotEmpty()) {
//            if (goingQueue.isNotEmpty() && answer - goingQueue.peek().second == bridge_length) {
//                nowWeight -= goingQueue.remove().first
//            }
//            if (weight - nowWeight - readyQueue.peek() >= 0) {
//                nowWeight += readyQueue.remove().apply {
//                    goingQueue.add(this to answer)
//                }
//            }
//            answer++
//        }
//
//        while (goingQueue.isNotEmpty()) {
//            if (answer - goingQueue.peek().second == bridge_length) {
//                goingQueue.remove()
//            }
//            answer++
//        }
//        return answer
//    }
//}