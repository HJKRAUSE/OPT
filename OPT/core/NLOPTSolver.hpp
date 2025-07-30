#include <nlopt.hpp>
#include <functional>
#include <vector>

namespace opt {

	class NLOPTSolver {
	public:
		using X = std::vector<double>;
		using F = std::function<double(const X&)>;

		NLOPTSolver(nlopt::algorithm algo, unsigned n);

		X optimize(const X& x0);

		void setMinObjective(const F& objective);
		void setMaxObjective(const F& objective);
		void setLowerBounds(const X& lb);
		void setUpperBounds(const X& ub);

		void setMaxEval(int max);

		void setFTolRel(double tol);
		void setFTolAbs(double tol);
		void setXTolRel(double tol);
		void setXTolAbs(double tol);

	private:
		nlopt::opt opt_;
		F objective_;
	};

	NLOPTSolver::NLOPTSolver(nlopt::algorithm algo, unsigned n) :
		opt_(algo, n) { }

	NLOPTSolver::X NLOPTSolver::optimize(const X& x0) {
		return opt_.optimize(x0);
	}

	void NLOPTSolver::setMinObjective(const F& objective) {
		objective_ = objective;
		auto wrapper = [](const X& x, X& grad, void* data) -> double {
			NLOPTSolver* solver = static_cast<NLOPTSolver*>(data);
			return solver->objective_(x);  // Call the stored function
			};
		opt_.set_min_objective(wrapper, this);
	}

	void NLOPTSolver::setMaxObjective(const F& objective) {
		objective_ = objective;
		auto wrapper = [](const X& x, X& grad, void* data) -> double {
			NLOPTSolver* solver = static_cast<NLOPTSolver*>(data);
			return solver->objective_(x);  // Call the stored function
			};
		opt_.set_max_objective(wrapper, this);
	}

	void NLOPTSolver::setLowerBounds(const X& lb) {
		opt_.set_lower_bounds(lb);
	}

	void NLOPTSolver::setUpperBounds(const X& ub) {
		opt_.set_upper_bounds(ub);
	}

	void NLOPTSolver::setXTolRel(double tol) {
		opt_.set_xtol_rel(tol);
	}

	void NLOPTSolver::setXTolAbs(double tol) {
		opt_.set_xtol_abs(tol);
	}

	void NLOPTSolver::setFTolRel(double tol) {
		opt_.set_ftol_rel(tol);
	}
	void NLOPTSolver::setFTolAbs(double tol) {
		opt_.set_ftol_abs(tol);
	}

	void NLOPTSolver::setMaxEval(int max) {
		opt_.set_maxeval(max);
	}

}