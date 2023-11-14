#include "main.h"

void setvar(char *varname, char *value, char ***env)
{
    char **var;

    var = getenvvarptr(varname, *env);

    if (!var)
        extend_env(env, cat(cat(varname, "="), value));
    else
        *var = cat(cat(varname, "="), value);

}
