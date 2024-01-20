#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �÷��̾� ���� ����ü
typedef struct {
    char name[50];
    int score;
} Player;

// ���� �ʱ�ȭ �Լ�
void initializeGame(Player* player1, Player* player2) {
    printf("�÷��̾� 1 �̸�: ");
    scanf("%s", player1->name);

    printf("�÷��̾� 2 �̸�: ");
    scanf("%s", player2->name);

    player1->score = 0;
    player2->score = 0;
}

// ���� ���� �Լ�
void playGame(Player* currentPlayer, Player* opponent) {
    int secretNumber, guess;

    secretNumber = rand() % 100 + 1; // 1���� 100 ������ ������ �� ����

    printf("%s, 1���� 100 ������ ���ڸ� ���纸����.\n", currentPlayer->name);

    do {
        printf("����: ");
        scanf("%d", &guess);

        if (guess == secretNumber) {
            printf("����! %s��(��) �̹� ���忡�� �¸��߽��ϴ�!\n", currentPlayer->name);
            currentPlayer->score++;
        }
        else {
            printf("Ʋ�Ƚ��ϴ�. �ٽ� �õ��ϼ���.\n");
        }

    } while (guess != secretNumber);

    printf("���� ���ھ�: %s %d - %s %d\n\n", player1.name, player1.score, player2.name, player2.score);
}

int main() {
    Player player1, player2;

    srand((unsigned int)time(NULL));

    initializeGame(&player1, &player2);

    while (1) {
        // �÷��̾� 1�� ����
        playGame(&player1, &player2);

        // �÷��̾� 2�� ����
        playGame(&player2, &player1);

        // ���� ���� ���� Ȯ��
        char choice;
        printf("������ ����Ͻðڽ��ϱ�? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y') {
            printf("������ �����մϴ�.\n");
            break;
        }
    }

    return 0;
}