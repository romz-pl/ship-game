#pragma once

#include <vector>
#include "Math.h"

class Game;
class Component;

class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead
    };

    Actor(Game* game);
    virtual ~Actor();

    // Update function called from Game (not overridable)
    void Update(float deltaTime);
    // Updates all the components attached to the actor (not overridable)
    void UpdateComponents(float deltaTime);
    // Any actor-specific update code (overridable)
    virtual void UpdateActor(float deltaTime);

    // Getters/setters
    const Vector2& GetPosition() const { return mPosition; }
    void SetPosition(const Vector2& pos) { mPosition = pos; }
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; }
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; }

    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    Game* GetGame() { return mGame; }


    // Add/remove components
    void AddComponent(Component* component);
    void RemoveComponent(Component* component);
private:
    // Actor's state
    State mState;

    // Transform
    Vector2 mPosition;
    float mScale;
    float mRotation;

    std::vector<Component*> mComponents;
    Game* mGame;
};
