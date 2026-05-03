(* Simple example that demonstrates the usage of the Raylib Bindings *)
open core
open raylib
open Random

val velocity: int = 8*2;
val WHITE:  int = 0xFFFFFFFF;
val RED:    int = 0xFF5050FF;
val GREEN:  int = 0xFF50FF50;
val BLUE:   int = 0xFFFF5050;
val YELLOW: int = 0xFF50FFFF;
val PURPLE: int = 0xFFFF50FF;
val CYAN:   int = 0xFFFFFF50;
val COLORS: int list = [RED, GREEN, BLUE, YELLOW, PURPLE, CYAN]
val radius: int = 20;
val balls_count = 10;

exception TODO of string

val gen = newgen ();

fun repeat (n: int) (x: 'a): 'a list =
    let
        fun repeat_impl (n: int) (acc: 'a list) =
            if n <= 0
            then acc
            else repeat_impl (n - 1) (x :: acc)
    in repeat_impl n [] end

fun choice (xs: 'a list): 'a = List.nth (xs, Random.range (0, List.length xs) gen)

fun collides_with_walls (x: int, y: int, w: int, h: int) =
    not (0 < x - radius andalso x + radius < w andalso 0 < y - radius andalso y + radius < h);

type ball = {
    x: int,
    y: int,
    dx: int,
    dy: int,
    color: int
}

fun ball_update ({x, y, dx, dy, color}: ball): ball = 
    let
        val w  = GetScreenWidth ()
        val h  = GetScreenHeight ()
        val dy = dy + 1
        val nx = x + dx
        val ny = y + dy
        val (x, dx, x_collision) = if collides_with_walls (nx, y, w, h) then (x, ~(dx*9) div 10, true) else (nx, dx, false)
        val (y, dy, y_collision) = if collides_with_walls (x, ny, w, h) then (y, ~(dy*9) div 10, true) else (ny, dy, false)
        val color = if x_collision orelse y_collision then choice COLORS else color
    in 
        {x = x, y = y, dx = dx, dy = dy, color = color}
    end

fun ball_render ({x, y, color, ...}: ball): unit =
    DrawCircle x y (Real.fromInt radius) color

fun ball_random (): ball =
    let
        val w  = GetScreenWidth ()
        val h  = GetScreenHeight ()
    in {x     = Random.range (radius, w - radius)  gen,
        y     = Random.range (radius, h - radius)  gen,
        dx    = Random.range (~velocity, velocity) gen,
        dy    = Random.range (~velocity, velocity) gen,
        color = choice COLORS}
    end

fun ball_random_at (x, y: int): ball =
    let val {dx, dy, color, ...} = ball_random () in
        {x = x, y = y, dx = dx, dy = dy, color = color}
    end

fun loop (bs: ball list) =
    if WindowShouldClose () then ()
    else
        let
            val bs = if IsMouseButtonPressed 0
                     then ball_random_at (GetMouseX (), GetMouseY ()) :: bs
                     else bs
        in
            BeginDrawing ();
            ClearBackground 0xFF181818;
            app ball_render bs;
            EndDrawing ();
            loop (map ball_update bs)
        end

val _ =
    (InitWindow 800 600 "Hello from Moscow ML my comrade";
     SetTargetFPS 60;
     loop [])
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
