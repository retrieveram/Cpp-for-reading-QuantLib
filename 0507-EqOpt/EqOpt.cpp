#include <ql/qldefines.hpp>
#include <ql/instruments/vanillaoption.hpp>
#include <ql/pricingengines/vanilla/analyticeuropeanengine.hpp>
#include <ql/processes/blackscholesprocess.hpp>
#include <ql/termstructures/yield/flatforward.hpp>
#include <ql/termstructures/volatility/equityfx/blackconstantvol.hpp>
#include <ql/exercise.hpp>
#include <ql/time/calendars/target.hpp>
#include <ql/utilities/dataformatters.hpp>
// #include <ql/errors.hpp>
#include <iostream>
#include <iomanip>
using namespace std;    using namespace QuantLib;

int main() {
  try {    
    // set up dates
    Date todaysDate(15, May, 1998);       Date settlementDate(17, May, 1998);
    Settings::instance().evaluationDate() = todaysDate;
    Calendar calendar = TARGET();         DayCounter dayCounter = Actual365Fixed();

    // our options
    Option::Type type(Option::Put);
    Real underlying       = 36;               Real strike           = 40;
    Spread dividendYield  = 0.00;             Rate riskFreeRate     = 0.06;
    Volatility volatility = 0.20;             Date maturity(17, May, 1999);

    cout << "Option type      = " << type                      << endl;
    cout << "Maturity         = " << maturity                  << endl;
    cout << "Underlying price = " << underlying                << endl;
    cout << "Strike           = " << strike                    << endl;
    cout << "Rist Free rate   = " << io::rate(riskFreeRate)    << endl;
    cout << "Div. yield       = " << io::rate(dividendYield)   << endl;
    cout << "Vol.             = " << io::volatility(volatility)<< endl;
    cout << endl;

    auto europeanExercise = ext::make_shared<EuropeanExercise>(maturity);
    auto underlyingH = makeQuoteHandle(underlying);

    // bootstrap the yield/dividend/vol curves
    Handle<YieldTermStructure> flatTermStructure(
        ext::make_shared<FlatForward>(settlementDate, riskFreeRate, dayCounter));
    Handle<YieldTermStructure> flatDividendTS(
        ext::make_shared<FlatForward>(settlementDate, dividendYield, dayCounter));
    Handle<BlackVolTermStructure> flatVolTS(
        ext::make_shared<BlackConstantVol>(settlementDate, calendar, volatility,
                                                                    dayCounter));
    auto payoff = ext::make_shared<PlainVanillaPayoff>(type, strike);
    auto bsmProcess = ext::make_shared<BlackScholesMertonProcess>(
                      underlyingH, flatDividendTS, flatTermStructure, flatVolTS);

    // Black-Scholes for European option
    VanillaOption europeanOption(payoff, europeanExercise);
    europeanOption.setPricingEngine(ext::make_shared<AnalyticEuropeanEngine>(bsmProcess));
    cout <<"Black-Scholes European Analytic = " << europeanOption.NPV() << endl; 
    // End test
    return 0;
  } 
  catch (QuantLib::Error& e) {std::cerr << e.what() << std::endl; return 1;}
  catch (...)        {std::cerr << "unknown error" << std::endl; return 1;}
}