#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl	harl;

	(void) argc;
	(void) argv;
	/* Debug complain */
	harl.complain("DEBUG");
	/* Info complain */
	harl.complain("INFO");
	/* Warning complain */
	harl.complain("WARNING");
	/* Error complain */
	harl.complain("ERROR");
	/* Unknown complain */
	harl.complain("");
	return (0);
}