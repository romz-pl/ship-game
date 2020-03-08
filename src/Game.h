#pragma once

#include "SDL2/SDL.h"
#include <unordered_map>
#include <string>
#include <vector>

class Actor;
class SpriteComponent;
class Ship;

class Game
{
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddActor(Actor* actor);
    void RemoveActor(Actor* actor);

    void AddSprite(SpriteComponent* sprite);
    void RemoveSprite(SpriteComponent* sprite);

    SDL_Texture* GetTexture(const std::string& fileName);
private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    void LoadData();
    void UnloadData();

    // Map of textures loaded
    std::unordered_map<std::string, SDL_Texture*> mTextures;

    // All the actors in the game
    std::vector<Actor*> mActors;
    // Any pending actors
    std::vector<Actor*> mPendingActors;

    // All the sprite components drawn
    std::vector<SpriteComponent*> mSprites;

    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    Uint32 mTicksCount;
    bool mIsRunning;
    // Track if we're updating actors right now
    bool mUpdatingActors;

    // Game-specific
    Ship* mShip; // Player's ship
};
