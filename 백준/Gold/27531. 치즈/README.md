# [Gold II] 치즈 - 27531 

[문제 링크](https://www.acmicpc.net/problem/27531) 

### 성능 요약

메모리: 19512 KB, 시간: 92 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 순열 사이클 분할

### 제출 일자

2024년 1월 12일 19:25:07

### 문제 설명

<p>치즈 애호가 제리는 $N$종류의 치즈를 모두 맛보기 위해 상점들을 방문하려고 한다.</p>

<p>$N$종류의 치즈는 편리하게 $1$부터 $N$까지 번호가 매겨져 있다.</p>

<p>상점도 $N$개가 있으며, $i$번째 상점은 치즈 $a_i$와 $b_i$를 $p_i$원에 묶음 판매한다.</p>

<p>특이하게도 ($a_1, a_2, \cdots, a_N$)과 ($b_1, b_2, \cdots, b_N$)은 모두 $1$부터 $N$까지의 수를 한 번씩 포함하는 순열이라고 한다.</p>

<p>이때 제리가 $1$부터 $N$까지 모든 종류의 치즈를 적어도 하나씩 구매하기 위해 지불해야 하는 최소 금액을 구하라.</p>

### 입력 

 <p>첫째 줄에 정수 $N$이 주어진다. ($1 \le N \le 200\,000$)</p>

<p>둘째 줄부터 $N$개의 줄에 걸쳐 정수 $a_i$, $b_i$, $p_i$가 공백을 사이에 두고 주어진다. ($1 \le a_i, b_i \le N,\ 1 \le p_i \le 1\,000$)</p>

<p>($a_1, a_2, \cdots, a_N$)과 ($b_1, b_2, \cdots, b_N$)은 모두 $1$부터 $N$까지의 수를 한 번씩 포함하는 순열이다.</p>

### 출력 

 <p>제리가 $1$부터 $N$까지의 치즈를 적어도 하나씩 구매하기 위해 지불해야 하는 최소 금액을 출력하라.</p>

