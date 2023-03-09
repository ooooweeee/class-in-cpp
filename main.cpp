#include <iostream>
#include <string>
#include <random>
#include <map>

using namespace std;

class Message {
public:
	Message(string txt) :
		txt{ txt },
		id{ createMessageId() } {};
	~Message() {};
	static Message* getInstance(string txt) {
		if (instance == nullptr) {
			instance = new Message(txt);
		}
		return instance;
	};
	virtual void Send() {};
private:
	int createMessageId() {
		random_device dev;
		return dev();
	};
	inline static Message* instance{ nullptr };
protected:
	string txt;
	int id;
};

class EmojiMessage : public Message
{
public:
	EmojiMessage(int num) :
		Message(transform(num)) {};
	~EmojiMessage() {};
	void Send() {
		cout << "message id is " << id << "\nmessage txt is " << txt << endl;
	};
private:
	inline static map<int, string> emoji{ {1, "happy"},{2, "sad"} };
	string transform(int num) {
		return emoji[num];
	};
};

int main() {
	EmojiMessage emoji(1);
	emoji.Send();

	return 0;
}