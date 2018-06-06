/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2008 Allen Kuo

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file discretizedcallablefixedratebond.hpp
    \brief Discretized callable fixed-rate bond class
*/

#ifndef quantlib_discretized_callable_fixed_rate_bond_hpp
#define quantlib_discretized_callable_fixed_rate_bond_hpp

#include <ql/experimental/callablebonds/callablebond.hpp>
#include <ql/discretizedasset.hpp>

namespace QuantLib {

    class DiscretizedCallableFixedRateBond : public DiscretizedAsset {
      public:
        DiscretizedCallableFixedRateBond(const CallableBond::arguments&,
                                         const Date& referenceDate,
                                         const DayCounter& dayCounter);
        void reset(Size size);
        std::vector<Time> mandatoryTimes() const;

      protected:
        void preAdjustValuesImpl();
        void postAdjustValuesImpl();

      private:
        CallableBond::arguments arguments_;
        Time redemptionTime_;
        std::vector<Time> couponTimes_;
        std::vector<Time> callabilityTimes_;
        void applyCallability(Size i);
        void addCoupon(Size i);
    };

}

#endif

