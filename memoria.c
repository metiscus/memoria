#include <chibi/eval.h>

int main()
{
    sexp ctx;
    ctx = sexp_make_eval_context(NULL, NULL, NULL, 0, 0);
    sexp_load_standard_env(ctx, NULL, SEXP_SEVEN);
    sexp_load_standard_ports(ctx, NULL, stdin, stdout, stderr, 0);
    sexp_gc_var2(obj1, obj2);
    sexp_gc_preserve2(ctx, obj1, obj2);

    obj1 = sexp_c_string(ctx, "data/test.scm", -1);
    sexp_load(ctx, obj1, NULL);

    obj1 = sexp_intern(ctx, "derp", -1);
    obj2 = sexp_cons(ctx, obj1, SEXP_NULL);
    sexp_eval(ctx, obj2, NULL);

    sexp_destroy_context(ctx);

    return 0;
}
