#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 플레이어 정보 구조체
typedef struct {
    char name[50];
    int score;
} Player;

// 게임 초기화 함수
void initializeGame(Player* player1, Player* player2) {
    printf("플레이어 1 이름: ");
    scanf("%s", player1->name);

    printf("플레이어 2 이름: ");
    scanf("%s", player2->name);

    player1->score = 0;
    player2->score = 0;
}

// 게임 진행 함수
void playGame(Player* currentPlayer, Player* opponent) {
    int secretNumber, guess;

    secretNumber = rand() % 100 + 1; // 1에서 100 사이의 무작위 수 생성

    printf("%s, 1에서 100 사이의 숫자를 맞춰보세요.\n", currentPlayer->name);

    do {
        printf("추측: ");
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("정답! %s이(가) 이번 라운드에서 승리했습니다!\n", currentPlayer->name);
            currentPlayer->score++;
        }
        else {
            printf("틀렸습니다. 다시 시도하세요.\n");
        }

    } while (guess != secretNumber);

    printf("현재 스코어: %s %d - %s %d\n\n", player1.name, player1.score, player2.name, player2.score);
}

int main() {
    Player player1, player2;

    srand((unsigned int)time(NULL));

    initializeGame(&player1, &player2);

    while (1) {
        // 플레이어 1의 차례
        playGame(&player1, &player2);

        // 플레이어 2의 차례
        playGame(&player2, &player1);

        // 게임 종료 여부 확인
        char choice;
        printf("게임을 계속하시겠습니까? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("게임을 종료합니다.\n");
            break;
        }
    }

    return 0;
}