#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // 정답 리스트
    const char *names[10] = {"이순신", "세종대왕", "아인슈타인", "칭기즈칸", "아우구스투스", "진시황", "소크라테스", "공자", "다빈치", "심재창"};
    // 질문 리스트
    const char *questions[10] = {
        "임진왜란의 1등 공신은?",
        "조선의 4번째 임금은?",
        "고전적 양자역학의 선지자는?",
        "인류 역사상 최대 규모의 단일 제국의 건국자는?",
        "2차 삼두정치의 승리자는?",
        "중국 최초의 황제는?",
        "플라톤의 스승은?",
        "논어에 기록된 어록의 주인은?",
        "미켈란젤로, 라파엘로와 더불어 르네상스 3대 거장으로 불리우는 이는?",
        "c프로그래밍 교수님 성함은?"
    };
    // 힌트 리스트
    const char *hints[10] = {
        "필사즉생 필생즉사",
        "훈민정음 창시자",
        "IQ 200",
        "몽골의 정복 군주",
        "로마 초대 황제",
        "중국 최초 통일",
        "너 자신을 알라",
        "유학의 창시자",
        "모나리자",
        "초성: ㅅㅈㅊ"
    };

    // 사용된 문제의 인덱스를 추적하기 위한 배열
    int n = 10;
    srand(time(NULL));
    int asked_indices[10] = {0};
    char in[20];

    // n개의 질문을 무작위로 뽑아 사용자에게 제시
    for (int i = 0; i < n; ++i) {
        int num;
        do {
            num = rand() % n;
        } while (asked_indices[num] == 1);
        asked_indices[num] = 1;

        printf("%d. %s (힌트를 원하신다면 '힌트'를 입력하십시오.)\n", i + 1, questions[num]);
        while (1) {
            scanf("%19s", in);
            if (strcmp(in, "힌트") == 0) {  // 사용자가 힌트를 요청하면 힌트 출력
                printf("힌트: %s\n", hints[num]);
                continue;
            }
            if (strcmp(in, names[num]) == 0) {  // 정답일 경우 정답 처리
                printf("정답입니다.\n");
                break;
            } else {
                printf("오답입니다.\n");  // 오답일 경우 오답 처리
            }
        }

        if (i != n - 1) {
            do {
                printf("문제를 더 푸시겠습니까? (네/아니오 중 하나를 선택하십시오.)\n");
                scanf("%19s", in);
                if (strcmp(in, "네") == 0 || strcmp(in, "아니오") == 0) {  // 계속 진행 여부 확인
                    break;
                } else {
                    printf("다시 응답하십시오.\n");  // 잘못된 응답 처리
                }
            } while (1);

            if (strcmp(in, "아니오") == 0) {  // 위 질문에서 아니요 가 나올시 종료
                break;
            }
        }
    }
    printf("프로그램을 종료합니다..\n");  // 모든 질문이 사용된 후 or 문제를 더 푸시겠습니까? 에서 아니오 가 나온 경우
    return 0;
}