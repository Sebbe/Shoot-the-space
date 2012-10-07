#ifndef UPDATEABLE_H
#define UPDATEABLE_H

class Updateable {
public:
	Updateable() { }
	virtual ~Updateable() {};
	virtual void Update(double deltaTime) {
		std::cout << "feil ";
	};
};

#endif