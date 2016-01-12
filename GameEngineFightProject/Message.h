#ifndef MESSAGE
#define MESSAGE

#include <string>

enum typeMSG { none, endTimer, death };
enum typeSource { None, p1, p2, Round };

class Message
{
	public:
		Message() : Message(typeMSG::none, typeSource::None) {};
		Message(typeMSG m, typeSource s);
		~Message();
		typeMSG getMsg() { return msg; };
		typeSource getSource() { return source; };

	private:
		typeMSG msg;
		typeSource source;
};
#endif
