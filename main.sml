(* Simple example that demonstrates the usage of the Raylib Bindings *)
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
(* Copyright 2026 Alexey Kutepov <reximkut@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *)
