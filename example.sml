(* An example that demonstrates the usage of the Raylib Bindings *)
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
val COR = (7, 10)
val max_lifetime = 60*3;

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
    color: int,
    lifetime: int
}

fun ball_update ({x, y, dx, dy, color, lifetime}: ball): ball option = 
    let
        val w  = GetScreenWidth ()
        val h  = GetScreenHeight ()
        val dy = dy + 1
        val nx = x + dx
        val ny = y + dy
        val (numCOR, denCOR) = COR
        val (x, dx, x_collision) = if collides_with_walls (nx, y, w, h) then (x, ~(dx*numCOR) div denCOR, true) else (nx, dx, false)
        val (y, dy, y_collision) = if collides_with_walls (x, ny, w, h) then (y, ~(dy*numCOR) div denCOR, true) else (ny, dy, false)
        val color = if x_collision orelse y_collision then choice COLORS else color
        val lifetime = lifetime + 1
    in 
      if lifetime >= max_lifetime
      then NONE
      else SOME {x = x, y = y, dx = dx, dy = dy, color = color, lifetime = lifetime}
    end

fun ball_render (balltex: raylib_texture) ({x, y, color, lifetime, ...}: ball): unit =
  let
    val alpha = 1.0 - (Real.fromInt lifetime)/(Real.fromInt max_lifetime)
    val color = ColorAlpha color (Math.sqrt alpha)
    val position = {x = Real.fromInt(x-radius), y = Real.fromInt(y-radius)}
    val rotation = alpha * 360.0
    val scale = Real.fromInt(radius)*2.0 / Real.fromInt(#width balltex)
  in
    DrawTextureEx balltex position rotation scale color
  end

fun ball_random (): ball =
    let
        val w  = GetScreenWidth ()
        val h  = GetScreenHeight ()
    in {x     = Random.range (radius, w - radius)  gen,
        y     = Random.range (radius, h - radius)  gen,
        dx    = Random.range (~velocity, velocity) gen,
        dy    = Random.range (~velocity, velocity) gen,
        lifetime = 0,
        color = choice COLORS}
    end

fun ball_random_at (x, y: int): ball =
    let val {dx, dy, color, lifetime, ...} = ball_random () in
        {x = x, y = y, dx = dx, dy = dy, color = color, lifetime = lifetime}
    end

fun loop (balltex: raylib_texture) (bs: ball list) (tutorial: bool) =
    if WindowShouldClose () then ()
    else
        let
            val (bs, tutorial) = 
              if IsMouseButtonPressed MOUSE_BUTTON_LEFT
              then (ball_random_at (GetMouseX (), GetMouseY ()) :: bs, false)
              else (bs, tutorial)
        in
            BeginDrawing ();
            ClearBackground 0xFF181818;
            if tutorial 
            then 
              let 
                val label = "Click here!" 
                val label_height = 32
                val label_width = MeasureText label label_height
                val screen_width = GetScreenWidth ()
                val screen_height = GetScreenHeight ()
                val x = (screen_width - label_width) div 2
                val y = (screen_height - label_height) div 2
              in
                DrawText label x y label_height WHITE
              end
            else app (ball_render balltex) bs;
            EndDrawing ();
            loop balltex (List.mapPartial ball_update bs) tutorial
        end

val _ =
    let
        val _ = InitWindow 800 600 "Hello from Moscow ML my comrades";
        val img = LoadImage "SoccerBall.png"
        val tex = LoadTextureFromImage img
    in
        SetTargetFPS 60;
        loop tex [] true
    end

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
