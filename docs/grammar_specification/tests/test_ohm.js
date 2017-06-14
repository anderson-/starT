const assert = require('assert');
var ohm = require('ohm-js');
var Matcher = require('ohm-js/src/Matcher');

var fs = require('fs');
var g = ohm.grammar(fs.readFileSync('src/starTv0.1.ohm'));

function print(text){
	process.stdout.write(text);
}

function println(text){
	process.stdout.write(text + '\n');
}

var category = 'None';
var test_count = 0;
var tests_failed = [];
var line_number = 0;
var matcher = new Matcher(g);
var header_printed;
fs.readFileSync('tests/tests0.1.in').toString().split('\n').forEach(function (line) {
	line_number++;
	var description = line.lastIndexOf('#');

	if (description == 0){
		category = line.substring(2);
		header_printed = false;
	} else if (line.trim() != ''){
		if (description > 0){
			var desc = line.substring(description+1).trim();
			line = line.substring(0, description);
			description = desc;
		} else {
			description = ''
		}
		test_count++;
		var passed, code;

		if (line.startsWith('true')) {
			code = line.substring(5).trim();
			passed = matcher.setInput(code).match(category).succeeded();
		} else if (line.startsWith('false')){
			code = line.substring(6).trim();
			passed = matcher.setInput(code).match(category).failed();
		}
		if (!header_printed){
			println('\nAsserting "' + category + '":');
			header_printed = true;
		}
		if (passed){
			print('.');
		} else {
			print('F');
			tests_failed.push([line_number, category, description, code, true]);
		}
	}
});

print('\n### RESULTS ###\n\n' + (test_count-tests_failed.length) + '/' + test_count + ' tests passed.\n');

if (tests_failed.length != 0){
	println('');
	tests_failed.forEach(function (test) {
		print('On line ' + test[0] + ': ' + test[1]);
		if (test[2] != ''){
			print(' "' + test[2] + '"');
		}
		println(' < ' + test[3] + ' > ' + test[4] + ' != ' + !test[4]);
	})
} else {
	println(' OK!');
}
