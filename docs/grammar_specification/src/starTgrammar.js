// Generated automatically by nearley
// http://github.com/Hardmath123/nearley
(function () {
function id(x) {return x[0]; }
var grammar = {
    Lexer: undefined,
    ParserRules: [
    {"name": "function_literal$ebnf$1", "symbols": ["block_statement"]},
    {"name": "function_literal$ebnf$1", "symbols": ["function_literal$ebnf$1", "block_statement"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "function_literal", "symbols": [{"literal":"F"}, "unsigned_integer", "function_literal$ebnf$1", {"literal":";"}]},
    {"name": "block_statement", "symbols": ["operation"]},
    {"name": "block_statement", "symbols": ["if_statement"]},
    {"name": "block_statement", "symbols": ["while_statement"]},
    {"name": "block_statement", "symbols": ["function_literal"]},
    {"name": "if_statement$ebnf$1", "symbols": ["block_statement"], "postprocess": id},
    {"name": "if_statement$ebnf$1", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "if_statement$ebnf$2$subexpression$1$ebnf$1", "symbols": []},
    {"name": "if_statement$ebnf$2$subexpression$1$ebnf$1", "symbols": ["if_statement$ebnf$2$subexpression$1$ebnf$1", "block_statement"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "if_statement$ebnf$2$subexpression$1", "symbols": [{"literal":":"}, "if_statement$ebnf$2$subexpression$1$ebnf$1"]},
    {"name": "if_statement$ebnf$2", "symbols": ["if_statement$ebnf$2$subexpression$1"], "postprocess": id},
    {"name": "if_statement$ebnf$2", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "if_statement", "symbols": [{"literal":"("}, "if_statement$ebnf$1", "if_statement$ebnf$2", {"literal":")"}]},
    {"name": "while_statement$ebnf$1", "symbols": ["block_statement"]},
    {"name": "while_statement$ebnf$1", "symbols": ["while_statement$ebnf$1", "block_statement"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "while_statement", "symbols": [{"literal":"["}, "while_statement$ebnf$1", {"literal":"]"}]},
    {"name": "load_cell", "symbols": [{"literal":"{"}, "string_literal", {"literal":"}"}]},
    {"name": "load_cell$ebnf$1", "symbols": []},
    {"name": "load_cell$ebnf$1$subexpression$1", "symbols": [{"literal":" "}, "numeric_literal"]},
    {"name": "load_cell$ebnf$1", "symbols": ["load_cell$ebnf$1", "load_cell$ebnf$1$subexpression$1"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "load_cell", "symbols": [{"literal":"{"}, "numeric_literal", "load_cell$ebnf$1", {"literal":"}"}]},
    {"name": "operation", "symbols": ["multi_cell_access_operation"]},
    {"name": "operation", "symbols": ["single_cell_access_operation"]},
    {"name": "single_cell_access_operation", "symbols": ["not_null_operator"]},
    {"name": "single_cell_access_operation", "symbols": ["zero_operator"]},
    {"name": "single_cell_access_operation$subexpression$1", "symbols": ["data_operator", {"literal":"'"}, "load_cell"]},
    {"name": "single_cell_access_operation", "symbols": ["single_cell_access_operation$subexpression$1"]},
    {"name": "single_cell_access_operation$subexpression$2", "symbols": ["memory_operator", "load_cell"]},
    {"name": "single_cell_access_operation", "symbols": ["single_cell_access_operation$subexpression$2"]},
    {"name": "single_cell_access_operation$subexpression$3", "symbols": ["flow_operator", "load_cell"]},
    {"name": "single_cell_access_operation", "symbols": ["single_cell_access_operation$subexpression$3"]},
    {"name": "not_null_operator", "symbols": [{"literal":"!"}]},
    {"name": "zero_operator", "symbols": [{"literal":"O"}]},
    {"name": "memory_operator", "symbols": ["left_operator"]},
    {"name": "memory_operator", "symbols": ["right_operator"]},
    {"name": "memory_operator", "symbols": ["out_operator"]},
    {"name": "memory_operator", "symbols": ["in_operator"]},
    {"name": "memory_operator", "symbols": ["store_operator"]},
    {"name": "memory_operator", "symbols": ["mem_jump_operator"]},
    {"name": "memory_operator", "symbols": ["copy_from_operator"]},
    {"name": "left_operator", "symbols": [{"literal":"<"}]},
    {"name": "right_operator", "symbols": [{"literal":">"}]},
    {"name": "out_operator", "symbols": [{"literal":"."}]},
    {"name": "in_operator", "symbols": [{"literal":","}]},
    {"name": "store_operator", "symbols": [{"literal":"s"}]},
    {"name": "mem_jump_operator", "symbols": [{"literal":"p"}]},
    {"name": "copy_from_operator", "symbols": [{"literal":"v"}]},
    {"name": "flow_operator", "symbols": ["run_operator"]},
    {"name": "flow_operator", "symbols": ["code_jmp_operator"]},
    {"name": "flow_operator", "symbols": ["break_operator"]},
    {"name": "flow_operator", "symbols": ["continue_operator"]},
    {"name": "flow_operator", "symbols": ["return_operator"]},
    {"name": "run_operator", "symbols": [{"literal":"~"}]},
    {"name": "code_jmp_operator", "symbols": [{"literal":"@"}]},
    {"name": "break_operator", "symbols": [{"literal":"x"}]},
    {"name": "continue_operator", "symbols": [{"literal":"c"}]},
    {"name": "return_operator", "symbols": [{"literal":"r"}]},
    {"name": "multi_cell_access_operation$subexpression$1", "symbols": ["data_operator", {"literal":"\""}]},
    {"name": "multi_cell_access_operation", "symbols": ["multi_cell_access_operation$subexpression$1"]},
    {"name": "multi_cell_access_operation", "symbols": ["memory_operator"]},
    {"name": "multi_cell_access_operation", "symbols": ["flow_operator"]},
    {"name": "data_operator", "symbols": ["math_operator"]},
    {"name": "data_operator", "symbols": ["binary_operator"]},
    {"name": "data_operator$subexpression$1", "symbols": ["relational_operator", {"literal":"?"}]},
    {"name": "data_operator", "symbols": ["data_operator$subexpression$1"]},
    {"name": "math_operator", "symbols": ["sum_operator"]},
    {"name": "math_operator", "symbols": ["sub_operator"]},
    {"name": "math_operator", "symbols": ["multi_operator"]},
    {"name": "math_operator", "symbols": ["div_operator"]},
    {"name": "math_operator", "symbols": ["mod_operator"]},
    {"name": "sum_operator", "symbols": [{"literal":"+"}]},
    {"name": "sub_operator", "symbols": [{"literal":"-"}]},
    {"name": "multi_operator", "symbols": [{"literal":"*"}]},
    {"name": "div_operator", "symbols": [{"literal":"/"}]},
    {"name": "mod_operator", "symbols": [{"literal":"%"}]},
    {"name": "relational_operator", "symbols": ["eq_operator"]},
    {"name": "relational_operator", "symbols": ["neq_operator"]},
    {"name": "relational_operator", "symbols": ["lt_operator"]},
    {"name": "relational_operator", "symbols": ["gt_operator"]},
    {"name": "relational_operator", "symbols": ["le_operator"]},
    {"name": "relational_operator", "symbols": ["ge_operator"]},
    {"name": "eq_operator", "symbols": [{"literal":"="}]},
    {"name": "neq_operator", "symbols": [{"literal":"!"}]},
    {"name": "lt_operator", "symbols": [{"literal":"<"}]},
    {"name": "gt_operator", "symbols": [{"literal":">"}]},
    {"name": "le_operator", "symbols": [{"literal":"l"}]},
    {"name": "ge_operator", "symbols": [{"literal":"g"}]},
    {"name": "binary_operator", "symbols": ["and_operator"]},
    {"name": "binary_operator", "symbols": ["or_operator"]},
    {"name": "binary_operator", "symbols": ["xor_operator"]},
    {"name": "binary_operator", "symbols": ["shift_left_operator"]},
    {"name": "binary_operator", "symbols": ["shift_right_operator"]},
    {"name": "and_operator", "symbols": [{"literal":"&"}]},
    {"name": "or_operator", "symbols": [{"literal":"|"}]},
    {"name": "xor_operator", "symbols": [{"literal":"^"}]},
    {"name": "shift_left_operator", "symbols": [{"literal":"L"}]},
    {"name": "shift_right_operator", "symbols": [{"literal":"R"}]},
    {"name": "numeric_literal", "symbols": ["int8_literal"]},
    {"name": "numeric_literal", "symbols": ["int16_literal"]},
    {"name": "numeric_literal", "symbols": ["int32_literal"]},
    {"name": "numeric_literal", "symbols": ["floating_point"]},
    {"name": "int8_literal", "symbols": ["signed_integer"]},
    {"name": "int16_literal", "symbols": [{"literal":"l"}, "signed_integer"]},
    {"name": "int32_literal", "symbols": [{"literal":"L"}, "signed_integer"]},
    {"name": "non_zero_integer$ebnf$1", "symbols": ["unsigned_integer"], "postprocess": id},
    {"name": "non_zero_integer$ebnf$1", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "non_zero_integer", "symbols": ["non_zero_integer$ebnf$1", /[1-9]/]},
    {"name": "signed_integer$ebnf$1$subexpression$1", "symbols": [{"literal":"+"}]},
    {"name": "signed_integer$ebnf$1$subexpression$1", "symbols": [{"literal":"-"}]},
    {"name": "signed_integer$ebnf$1", "symbols": ["signed_integer$ebnf$1$subexpression$1"], "postprocess": id},
    {"name": "signed_integer$ebnf$1", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "signed_integer", "symbols": ["signed_integer$ebnf$1", "unsigned_integer"]},
    {"name": "unsigned_integer$ebnf$1", "symbols": [/[0-9]/]},
    {"name": "unsigned_integer$ebnf$1", "symbols": ["unsigned_integer$ebnf$1", /[0-9]/], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "unsigned_integer", "symbols": ["unsigned_integer$ebnf$1"]},
    {"name": "floating_point$ebnf$1$subexpression$1$ebnf$1", "symbols": []},
    {"name": "floating_point$ebnf$1$subexpression$1$ebnf$1", "symbols": ["floating_point$ebnf$1$subexpression$1$ebnf$1", /[0-9]/], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "floating_point$ebnf$1$subexpression$1", "symbols": [{"literal":"."}, "floating_point$ebnf$1$subexpression$1$ebnf$1"]},
    {"name": "floating_point$ebnf$1", "symbols": ["floating_point$ebnf$1$subexpression$1"], "postprocess": id},
    {"name": "floating_point$ebnf$1", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "floating_point$ebnf$2$subexpression$1$ebnf$1", "symbols": [{"literal":"e"}], "postprocess": id},
    {"name": "floating_point$ebnf$2$subexpression$1$ebnf$1", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "floating_point$ebnf$2$subexpression$1", "symbols": ["floating_point$ebnf$2$subexpression$1$ebnf$1", "signed_integer"]},
    {"name": "floating_point$ebnf$2", "symbols": ["floating_point$ebnf$2$subexpression$1"], "postprocess": id},
    {"name": "floating_point$ebnf$2", "symbols": [], "postprocess": function(d) {return null;}},
    {"name": "floating_point", "symbols": [{"literal":"f"}, "signed_integer", "floating_point$ebnf$1", "floating_point$ebnf$2"]},
    {"name": "string_literal$ebnf$1", "symbols": []},
    {"name": "string_literal$ebnf$1$subexpression$1", "symbols": [/[^\\"]/]},
    {"name": "string_literal$ebnf$1$subexpression$1", "symbols": [{"literal":"\\"}, /["\\/bfnrt]/]},
    {"name": "string_literal$ebnf$1", "symbols": ["string_literal$ebnf$1", "string_literal$ebnf$1$subexpression$1"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "string_literal", "symbols": [{"literal":"\""}, "string_literal$ebnf$1", {"literal":"\""}]}
]
  , ParserStart: "function_literal"
}
if (typeof module !== 'undefined'&& typeof module.exports !== 'undefined') {
   module.exports = grammar;
} else {
   window.grammar = grammar;
}
})();
