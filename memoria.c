#include <chibi/eval.h>

int main()
{
    sexp ctx;
    ctx = sexp_make_eval_context(NULL, NULL, NULL, 0, 0);
    sexp_load_standard_env(ctx, NULL, SEXP_SEVEN);
    sexp_load_standard_ports(ctx, NULL, stdin, stdout, stderr, 0);
    sexp_destroy_context(ctx);

    return 0;
}
