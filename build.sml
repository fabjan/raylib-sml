app load ["Process", "String"];
open Process;

infix 8 |>;
fun x |> f = f x;

fun println (s: string) =
    (print s; print "\n");

fun quote_string (s: string): string =
    if String.isSubstring " " s
    then "\""^s^"\""
    else s

exception Cmd_Failed of string;

fun cmd (args: string list) =
    let
        val cmd_line = args |> map quote_string |> String.concatWith " "
    in
        (("CMD: " ^ cmd_line) |> println;
         if cmd_line |> system |> isSuccess |> not
         then raise Cmd_Failed cmd_line
         else ())
    end;

val _ =
    (let
         val mosmlhome = case getEnv "MOSMLHOME" of SOME path => path | NONE => ""
     in
         cmd ["cc", "-Wall", "-Wextra", "-o", "raylib_parser", "raylib_parser.c"];
         cmd ["./raylib_parser",
              "-f", "SML",
              "-i", "./raylib-5.5_linux_amd64/include/raylib.h",
              "-o", "raylib.sml"];
         cmd ["cc",
              "-fPIC",
              "-I"^mosmlhome^"/include/mosml",
              "-I./raylib-5.5_linux_amd64/include/",
              "-o", "libmraylib.so",
              "-shared",
              "raylib.sml.c",
              "-L./raylib-5.5_linux_amd64/lib/",
              "-l:libraylib.a",
              "-lm"];
         cmd [mosmlhome^"/bin/mosmlc", "-o", "main", "core.sml", "raylib.sml", "main.sml"];
         exit success
     end) handle Cmd_Failed cmd_line => exit failure
