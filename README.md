# Unreal Engine 5 notes

## Sources
1. <a href="https://www.youtube.com/watch?v=KQgOqyYoHAs">Beginners Intro to UE5 - Create a Game in 3 Hours in Unreal Engine 5<a>
2. <a href="https://github.com/Allar/ue5-style-guide">Example Style Guide<a>

## Development Performance Optimization
1. Turn off realtime rendering (CTRL+R)
2. Set Dynamic Global Illumination Method to None
3. Set Reflection Method to None
4. Set Shadow Map Method to Shadow Map

## Debugging
1. GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Orange, FString::Printf(TEXT("Z Normal: %f"), HitDirection));