//import java.util.concurrent.atomic.AtomicBoolean
//
//class Solution {
//    @Volatile
//    var a = AtomicBoolean()
//    fun solution(n: Long): Long {
//
//        synchronized(a){
//
//        }
//        return n.toString()
//            .toCharArray()
//            .run {
//                sortDescending()
//                joinToString("")
//            }.toLong()
//
//    }
//}