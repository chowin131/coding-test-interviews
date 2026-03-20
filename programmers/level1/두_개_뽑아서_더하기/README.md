# 두 개 뽑아서 더하기

## 📌 문제 정보

| 항목 | 내용 |
|---|---|
| 플랫폼 | 프로그래머스 |
| 문제 링크 | [두 개 뽑아서 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/68644) |
| 난이도 | Level 1 |
| 카테고리 | #배열, #완전탐색 |
| 풀이 날짜 | 2026-03-20 |
| 소요 시간 | 15분 |

---

## 📋 문제 설명

> 정수 배열 `numbers`에서 서로 다른 인덱스의 두 수를 뽑아 더할 수 있는 모든 수를 배열에 오름차순으로 담아 반환합니다.

---

## 💡 풀이 접근법

1. 이중 반복문으로 모든 두 수의 조합 탐색
2. 합을 `set`에 저장하여 중복 제거
3. 정렬 후 반환

---

## 🖥️ 내 풀이 코드

```python
def solution(numbers):
    result = set()
    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            result.add(numbers[i] + numbers[j])
    return sorted(result)
```

---

## ⏱️ 시간/공간 복잡도

- **시간 복잡도**: O(N²)
- **공간 복잡도**: O(N²)

---

## ✅ 결과

- [x] 정확성 테스트 통과

---

## 📝 회고

### 잘한 점
- `set`을 활용해 중복을 간단히 제거

### 개선할 점
- `itertools.combinations`를 활용하면 더 파이써닉하게 작성 가능

### 배운 점
- 완전탐색 문제에서 중복 제거가 필요할 때 `set` 활용
