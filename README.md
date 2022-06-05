# Unreal Engine 5 notes

## Sources
1. <a href="https://www.youtube.com/watch?v=KQgOqyYoHAs">Beginners Intro to UE5 - Create a Game in 3 Hours in Unreal Engine 5<a>
2. <a href="https://www.youtube.com/watch?v=Rr9gYK50IuY">Unreal Engine 4 - Making a 2D Platformer in UE4 - Full Length<a>

## Development Performance Optimization
- Turn off realtime rendering (CTRL+R)
- Set Dynamic Global Illumination Method to None
- Set Reflection Method to None
- Set Shadow Map Method to Shadow Map

## Debugging
- GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("Z Normal: %f"), HitDirection));

## 2d
**Creating sprites**
1. Import png's into project assets
2. Right click -> Sprite actions -> Apply Paper2D Texture Settings
3. Right click -> Sprite actions -> Extract Sprites
4. Select sprites for single animation -> Right click -> Create Flipbook (switch to grid & set correct tile size or use auto with changing pivot point)

