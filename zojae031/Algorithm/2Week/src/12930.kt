//class Solution {
//    fun solution(s: String): String {
//        val answer = StringBuilder()
//
//        s.split(" ").also { splitList ->
//
//            splitList.mapIndexed { listIndex, string ->
//
//                string.forEachIndexed { stringIndex, ch ->
//                    if (stringIndex % 2 == 0) {
//                        answer.append(ch.toUpperCase())
//                    } else answer.append(ch.toLowerCase())
//                }
//
//                if (listIndex != splitList.lastIndex) answer.append(" ")
//            }
//        }
//        return answer.toString()
//    }
//}