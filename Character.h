#include "raylib.h"
#include "BaseCharacter.h"

class Character : public BaseCharacter{
public:
    Character(int windowWidth, int windowHeight);
    void virtual update(float deltaTime) override;

private:

};