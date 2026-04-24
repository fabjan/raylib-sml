(* Just some things that I wish were in the standard library of SML *)

(* The pipe operator, of course *)
infix 8 |>;
fun op |> (x, f) = f x;

fun println (s: string) =
    (print s; print "\n");
