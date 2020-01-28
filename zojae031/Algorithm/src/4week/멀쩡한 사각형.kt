fun main() {
    Solution().run {
        solution(100000000, 99999999)
            .also { println(it) }//80
    }
}

class Solution {
    fun solution(w: Int, h: Int): Long {
        var answer: Long = 0
        val min = Integer.min(w, h).toLong()
        val max = Integer.max(w, h).toLong()

        when {
            max == min -> {//정사각형이면 그대로 반환
                answer = min
            }
            min.toInt() % 2 == 0 -> {//짝수 일때
                answer = if (max.toInt() % min.toInt() == 0) {//나누어 떨어지는 경우
                    max
                } else {
                    val cal = max / min + 1
                    if (max % min < min / 2) {//같은값들
                        (min * cal)
                    } else {//다른값들
                        (min * cal) + (max % min - min / 2) * 2
                    }

                }
            }
            else -> {//홀수 일때
                answer = if (max.toInt() % min.toInt() == 0) {//나누어 떨어지는 경우
                    max
                } else {//그렇지 않은 경우
                    val cal = max / min + 1
                    (min * cal + (max % min - 1))
                }
            }
        }

        return max * min - answer
    }
}