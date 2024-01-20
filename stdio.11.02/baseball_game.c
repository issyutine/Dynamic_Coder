#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumStrike(int* random, int* num) {
    int strike = 0;
    for (int i = 0; i < 3; i++) {
        if (random[i] == num[i]) strike += 1;
    }

    return strike;
}

int NumBall(int* random, int* num) {
    int ball = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (random[i] == num[j]) ball += 1;
        }
    }

    return ball;
}

void game(int* random, int* num) {
    printf("세 자리 숫자를 입력해주세요 : ");
    scanf_s("%d %d %d", &num[0], &num[1], &num[2]);

    int strike = NumStrike(random, num);
    int ball = NumBall(random, num);
    printf("%d 스트라이크, %d 볼\n", strike, ball - strike);

    if (strike == 3) {
        printf("축하합니다! 정답을 맞추셨습니다!\n");
    }
    else game(random, num);
}


int main()
{
    printf("숫자 야구게임에 오신 것을 환영합니다!\n");

    srand(time(NULL));
    int random[3];
    for (int i = 0; i < 3; i++) {
        random[i] = rand() % 9 + 1;
    }

    int num[3];
    game(random, num);

    return 0;
}