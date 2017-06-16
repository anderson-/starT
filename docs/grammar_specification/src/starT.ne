function_literal -> "F" unsigned_integer block_statement:+ ";"

block_statement ->
            operation
          | if_statement
          | while_statement
          | function_literal

if_statement -> "(" block_statement:? (":" block_statement:*):? ")"

while_statement -> "[" block_statement:+ "]"

load_cell ->
            "{" string_literal "}"
          | "{" numeric_literal (" " numeric_literal):* "}"

operation ->
            multi_cell_access_operation
          | single_cell_access_operation

single_cell_access_operation ->
            not_null_operator
          | zero_operator
          | (data_operator "'" load_cell)
          | (memory_operator load_cell)
          | (flow_operator load_cell)

# compiled value \(b|l|L)

not_null_operator -> "!"
zero_operator -> "O"

memory_operator ->
            left_operator
          | right_operator
          | out_operator
          | in_operator
          | store_operator
          | mem_jump_operator
          | copy_from_operator

left_operator -> "<"
right_operator -> ">"
out_operator -> "."
in_operator -> ","
store_operator -> "s"
mem_jump_operator -> "p"
copy_from_operator -> "v"

flow_operator ->
            run_operator
          | code_jmp_operator
          | break_operator
          | continue_operator
          | return_operator

run_operator -> "~"
code_jmp_operator -> "@"
break_operator -> "x"
continue_operator -> "c"
return_operator -> "r"

multi_cell_access_operation ->
            (data_operator "\"")
          | memory_operator
          | flow_operator

data_operator ->
            math_operator
          | binary_operator
          | (relational_operator "?")

math_operator ->
            sum_operator
          | sub_operator
          | multi_operator
          | div_operator
          | mod_operator

sum_operator -> "+"
sub_operator -> "-"
multi_operator -> "*"
div_operator -> "/"
mod_operator -> "%"

relational_operator ->
            eq_operator
          | neq_operator
          | lt_operator
          | gt_operator
          | le_operator
          | ge_operator

eq_operator -> "="
neq_operator -> "!"
lt_operator -> "<"
gt_operator -> ">"
le_operator -> "l"
ge_operator -> "g"

binary_operator ->
            and_operator
          | or_operator
          | xor_operator
          | shift_left_operator
          | shift_right_operator

and_operator -> "&"
or_operator -> "|"
xor_operator -> "^"
shift_left_operator -> "L"
shift_right_operator -> "R"

numeric_literal ->
            int8_literal
          | int16_literal
          | int32_literal
          | floating_point

int8_literal -> signed_integer
int16_literal -> "l" signed_integer
int32_literal -> "L" signed_integer

non_zero_integer -> unsigned_integer:? [1-9]
signed_integer -> ("+" | "-"):? unsigned_integer
unsigned_integer -> [0-9]:+
floating_point -> "f" signed_integer ("." [0-9]:*):? ("e":? signed_integer):?
string_literal -> "\"" ([^\\"] | "\\" ["\\/bfnrt]):* "\""
