class Solution {
    fun solution(n: Long): Long {


        return n.toString()
            .toCharArray()
            .run {
                sortDescending()
                joinToString("")
            }.toLong()

    }
}