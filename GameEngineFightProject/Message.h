#ifndef MESSAGE
#define MESSAGE

#include <string>

enum typeMSG { endTimer, death };
enum typeSource { p1, p2, Round };

class Message
{
	public:
		Message(typeMSG m, typeSource s);
		~Message();
		typeMSG getMsg() { return msg; };
		typeSource getSource() { return source; };

	private:
		typeMSG msg;
		typeSource source;
};
#endif
