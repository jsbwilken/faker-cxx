#pragma once

#include <optional>
#include <string>

#include "faker-cxx/types/BicCountry.h"
#include "faker-cxx/types/IbanCountry.h"
#include "faker-cxx/types/Precision.h"
#include "types/Country.h"

namespace faker
{
enum class CreditCardType
{
    AmericanExpress,
    Discover,
    MasterCard,
    Visa
};

class Finance
{
public:
    /**
     * @brief Returns a random currency code.
     *
     * @returns Code of the currency.
     *
     * @code
     * Finance::currencyCode() // "USD"
     * @endcode
     */
    static std::string currencyCode();

    /**
     * @brief Returns a random account type.
     *
     * @returns Account type.
     *
     * @code
     * Finance::accountType() // "Savings"
     * @endcode
     */
    static std::string accountType();

    /**
     * @brief Generates a random amount between the given bounds (inclusive).

     * @param min The lower bound for the amount. Defaults to `0`.
     * @param max The upper bound for the amount. Defaults to `1000`.
     * @param precision The number of decimal points of precision for the amount. Defaults to `Precision::TwoDp`.
     * @param symbol The symbol used to prefix the amount. Defaults to `""`.
     *
     * @returns Amount of money as string.
     *
     * @code
     * Finance::amount() // "720.18"
     * Finance::amount(5, 10) // "4.22"
     * Finance::amount(5, 10, Precision::ZeroDp) // "4"
     * Finance::amount(5, 10, Precision::TwoDp, "$") // "$5.85"
     * @endcode
     */
    static std::string amount(double min = 0, double max = 1000, Precision precision = Precision::TwoDp,
                              const std::string& symbol = "");

    /**
     * Generates a random iban.
     *
     * @param country The country from which you want to generate an IBAN, if none is provided a random country
     will be used.
     *
     * @returns IBAN.
     *
     * @code
     * Finance::iban(IbanCountry::Poland) // "PL61109010140000071219812874"
     * @endcode
     */
    static std::string iban(std::optional<IbanCountry> country = std::nullopt);

    /**
     * Generates a random bic.
     *
     * @param country The country from which you want to generate a BIC, if none is provided a random country
     will be used.
     *
     * @returns BIC.
     *
     * @code
     * Finance::bic(BicCountry::Poland) // "BREXPLPWMUL"
     * @endcode
     */
    static std::string bic(std::optional<BicCountry> country = std::nullopt);

    /**
     * Generates a random account number.
     *
     * @param length The length of the account number. Defaults to `8`.
     *
     * @returns Account number.
     *
     * @code
     * Finance::accountNumber() // "92842238"
     * Finance::accountNumber(26) // "55875455514825927518796290"
     * @endcode
     */
    static std::string accountNumber(unsigned length = 8);

    /**
     * Generates a random PIN number.
     *
     * @param length The length of the PIN to generate. Defaults to `4`.
     *
     * @returns PIN number.
     *
     * @code
     * Finance::pin() // "5067"
     * Finance::pin(8) // "21378928"
     * @endcode
     */
    static std::string pin(unsigned length = 4);

    /**
     * Generates a random routing number.
     *
     * @returns Routing number.
     *
     * @code
     * Finance::routingNumber() // "522814402"
     * @endcode
     */
    static std::string routingNumber();

    /**
     * Generates a random credit card number.
     *
     * @param creditCardType The type of the credit card.
     *
     * @returns Credit card number.
     *
     * @code
     * Finance::creditCardNumber() // "4882664999007"
     * @endcode
     */
    static std::string creditCardNumber(std::optional<CreditCardType> creditCardType = std::nullopt);

    /**
     * Generates a random credit card CVV.
     *
     * @returns Credit card CVV.
     *
     * @code
     * Finance::creditCardCvv() // "506"
     * @endcode
     */
    static std::string creditCardCvv();
};
}
