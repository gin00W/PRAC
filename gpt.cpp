#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 블라인드 처리 함수
void blindCard(const string& filename) {
    ofstream file_to_blind(filename, ios::trunc); // 쓰기 모드로 파일 열기 (기존 내용 삭제)
    if (!file_to_blind) {
        :cerr << "파일을 찾을 수 없습니다: " << filename;
        return;
    }

    // 파일 내용을 모두 지워서 블라인드 처리
    file_to_blind << "이 카드는 블라인드 처리되었습니다.";
    file_to_blind.close();
}

int main() {
    vector<string> cards = {
        "A", "A", "B", "B", "C", "C" // 카드 종류를 문자열로 표현 (단순화를 위해 3쌍만 사용)
    };

    // 카드 섞기
    random_shuffle(cards.begin(), cards.end());

    // 카드 파일 생성 및 초기화
    for (const auto& card : cards) {
        string filename = card + ".txt"; // 카드마다 파일명을 지정 (예: "A.txt", "B.txt", "C.txt")
        ofstream card_file(filename); // 파일 생성

        // 파일에 카드 정보 저장
        card_file << card << ;
        card_file.close();
    }

    // 게임 진행
    cout << "카드 짝 맞추기 게임을 시작합니다." ;

    while (!cards.empty()) {
        // 사용자로부터 카드를 선택 받음 (여기서는 무작위로 선택하는 것으로 가정)
        int index = rand() % cards.size();
        string selected_card = cards[index];

        // 사용자에게 선택한 카드를 보여줌 (실제 게임에서는 그림 등으로 표현 가능)
        cout << "선택한 카드: " << selected_card;

        // 해당 카드 파일을 블라인드 처리하고, 카드 리스트에서 제거
        blindCard(selected_card + ".txt");
        cards.erase(cards.begin() + index);

        // 잠시 딜레이를 줘서 카드가 블라인드 처리된 것처럼 보이도록 함 (예시를 위해 1초 딜레이)
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "모든 카드를 맞추셨습니다! 게임 종료!";

    return 0;
}
