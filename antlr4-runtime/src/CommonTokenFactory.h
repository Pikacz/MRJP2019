/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "TokenFactory.h"

namespace antlr4 {

  /**
   * This default implementation of { TokenFactory} creates
   * { CommonToken} objects.
   */
  class ANTLR4CPP_PUBLIC CommonTokenFactory : public TokenFactory<CommonToken> {
  public:
    /**
     * The default { CommonTokenFactory} instance.
     *
     * <p>
     * This token factory does not explicitly copy token text when constructing
     * tokens.</p>
     */
    static const Ref<TokenFactory<CommonToken>> DEFAULT;

  protected:
    /**
     * Indicates whether { CommonToken#setText} should be called after
     * constructing tokens to explicitly set the text. This is useful for cases
     * where the input stream might not be able to provide arbitrary substrings
     * of text from the input after the lexer creates a token (e.g. the
     * implementation of { CharStream#getText} in
     * { UnbufferedCharStream} throws an
     * { UnsupportedOperationException}). Explicitly setting the token text
     * allows { Token#getText} to be called at any time regardless of the
     * input stream implementation.
     *
     * <p>
     * The default value is { false} to avoid the performance and memory
     * overhead of copying text for every token unless explicitly requested.</p>
     */
    const bool copyText;

  public:
    /**
     * Constructs a { CommonTokenFactory} with the specified value for
     * { #copyText}.
     *
     * <p>
     * When { copyText} is { false}, the { #DEFAULT} instance
     * should be used instead of constructing a new instance.</p>
     *
     * @param copyText The value for { #copyText}.
     */
    CommonTokenFactory(bool copyText);

    /**
     * Constructs a { CommonTokenFactory} with { #copyText} set to
     * { false}.
     *
     * <p>
     * The { #DEFAULT} instance should be used instead of calling this
     * directly.</p>
     */
    CommonTokenFactory();

    virtual std::unique_ptr<CommonToken> create(std::pair<TokenSource*, CharStream*> source, size_t type,
      const std::string &text, size_t channel, size_t start, size_t stop, size_t line, size_t charPositionInLine) override;

    virtual std::unique_ptr<CommonToken> create(size_t type, const std::string &text) override;
  };

} // namespace antlr4
