open core
open raylib

val radius: int = 100;
val velocity: int = 8;

fun collides_with_walls (x: int, y: int, w: int, h: int) =
    not (0 < x - radius andalso x + radius < w andalso 0 < y - radius andalso y + radius < h);

fun loop ((x, dx): int * int, (y, dy): int * int) =
    if WindowShouldClose () then ()
    else let
        val w  = GetScreenWidth ()
        val h  = GetScreenHeight ()
        val nx = x + dx
        val ny = y + dy
    in 
        BeginDrawing ();
        ClearBackground 0xFF181818;
        DrawCircle x y (Real.fromInt radius) 0xFFFF5050;
        EndDrawing ();
        loop (
            if collides_with_walls (nx, y, w, h) then (x, ~dx) else (nx, dx),
            if collides_with_walls (x, ny, w, h) then (y, ~dy) else (ny, dy)
        )
    end

val _ =
    (InitWindow 800 600 "Hello from Moscow ML my comrade";
     SetTargetFPS 60;
     loop ((radius*2, velocity), (radius*2, velocity)));
